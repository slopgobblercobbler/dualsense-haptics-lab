// DualSense Haptics Lab - Core JavaScript Application
// Web Audio API Synthesizer & Adaptive Trigger Curve Visualizer

document.addEventListener('DOMContentLoaded', () => {
    // State management
    const state = {
        audio: {
            context: null,
            leftOsc: null,
            rightOsc: null,
            leftGain: null,
            rightGain: null,
            analyser: null,
            isPlaying: false,
            leftFreq: 120,
            rightFreq: 180,
            leftGainVal: 0.75,
            rightGainVal: 0.60,
            leftWave: 'sine',
            rightWave: 'sine'
        },
        triggers: {
            channel: 'left', // left, right, both
            mode: 'feedback', // off, feedback, weapon, vibration, slope
            startPos: 2,
            endPos: 8,
            strength: 6,
            frequency: 10,
            pullDepth: 45
        }
    };

    // DOM Elements - Navigation
    const navButtons = document.querySelectorAll('.nav-btn');
    const labModules = document.querySelectorAll('.lab-module');

    navButtons.forEach(btn => {
        btn.addEventListener('click', () => {
            const targetTab = btn.getAttribute('data-tab');
            navButtons.forEach(b => b.classList.remove('active'));
            labModules.forEach(m => m.classList.remove('active'));
            btn.classList.add('active');
            document.getElementById(`tab-${targetTab}`).classList.add('active');
        });
    });

    // Logging utility
    function logEvent(message, type = 'info') {
        const terminal = document.getElementById('terminal-logs');
        if (!terminal) return;
        const now = new Date();
        const timeStr = now.toTimeString().split(' ')[0] + '.' + String(now.getMilliseconds()).padStart(3, '0');
        const entry = document.createElement('div');
        entry.className = `log-entry ${type}`;
        entry.innerHTML = `<span class="time">[${timeStr}]</span> ${message}`;
        terminal.appendChild(entry);
        terminal.scrollTop = terminal.scrollHeight;
    }

    // --- WEB AUDIO API SYNTHESIZER ---
    const toggleAudioBtn = document.getElementById('toggle-audio-engine');
    const audioStatusText = document.getElementById('audio-status-text');
    const masterPlayBtn = document.getElementById('global-master-play');

    function initAudioEngine() {
        if (state.audio.context) return;
        try {
            const AudioContext = window.AudioContext || window.webkitAudioContext;
            state.audio.context = new AudioContext();

            // Analyser for oscilloscope
            state.audio.analyser = state.audio.context.createAnalyser();
            state.audio.analyser.fftSize = 2048;

            // Left Actuator chain
            state.audio.leftOsc = state.audio.context.createOscillator();
            state.audio.leftGain = state.audio.context.createGain();
            state.audio.leftOsc.type = state.audio.leftWave;
            state.audio.leftOsc.frequency.setValueAtTime(state.audio.leftFreq, state.audio.context.currentTime);
            state.audio.leftGain.gain.setValueAtTime(0, state.audio.context.currentTime);
            state.audio.leftOsc.connect(state.audio.leftGain);
            state.audio.leftGain.connect(state.audio.analyser);

            // Right Actuator chain
            state.audio.rightOsc = state.audio.context.createOscillator();
            state.audio.rightGain = state.audio.context.createGain();
            state.audio.rightOsc.type = state.audio.rightWave;
            state.audio.rightOsc.frequency.setValueAtTime(state.audio.rightFreq, state.audio.context.currentTime);
            state.audio.rightGain.gain.setValueAtTime(0, state.audio.context.currentTime);
            state.audio.rightOsc.connect(state.audio.rightGain);
            state.audio.rightGain.connect(state.audio.analyser);

            // Connect to destination (stereo panned if possible, else mono master)
            state.audio.analyser.connect(state.audio.context.destination);

            state.audio.leftOsc.start();
            state.audio.rightOsc.start();

            audioStatusText.textContent = "Audio engine active (48kHz Voice Coils)";
            toggleAudioBtn.innerHTML = `<i class="fa-solid fa-power-off"></i> Disable Web Audio Engine`;
            toggleAudioBtn.classList.add('btn-primary');
            toggleAudioBtn.classList.remove('btn-sm');
            logEvent("Web Audio synthesizer initialized successfully.", "success");
        } catch (e) {
            logEvent(`Failed to initialize Web Audio: ${e.message}`, "error");
        }
    }

    function toggleAudioPlayback() {
        if (!state.audio.context) {
            initAudioEngine();
        }
        
        if (state.audio.context.state === 'suspended') {
            state.audio.context.resume();
        }

        state.audio.isPlaying = !state.audio.isPlaying;
        const now = state.audio.context.currentTime;

        if (state.audio.isPlaying) {
            state.audio.leftGain.gain.setTargetAtTime(state.audio.leftGainVal * 0.3, now, 0.05);
            state.audio.rightGain.gain.setTargetAtTime(state.audio.rightGainVal * 0.3, now, 0.05);
            masterPlayBtn.innerHTML = `<i class="fa-solid fa-stop"></i> Stop Haptic Stream`;
            masterPlayBtn.classList.add('danger');
            logEvent("Haptic stream started across dual voice coils.", "success");
        } else {
            state.audio.leftGain.gain.setTargetAtTime(0, now, 0.05);
            state.audio.rightGain.gain.setTargetAtTime(0, now, 0.05);
            masterPlayBtn.innerHTML = `<i class="fa-solid fa-play"></i> Test Haptic Stream`;
            masterPlayBtn.classList.remove('danger');
            logEvent("Haptic stream stopped.", "info");
        }
    }

    if (toggleAudioBtn) {
        toggleAudioBtn.addEventListener('click', () => {
            if (!state.audio.context) initAudioEngine();
            else toggleAudioPlayback();
        });
    }

    if (masterPlayBtn) {
        masterPlayBtn.addEventListener('click', toggleAudioPlayback);
    }

    // --- RUMBLE CONTROLS & BINDINGS ---
    const leftFreqInput = document.getElementById('left-freq');
    const leftFreqVal = document.getElementById('left-freq-val');
    const leftGainInput = document.getElementById('left-gain');
    const leftGainVal = document.getElementById('left-gain-val');
    const leftValBadge = document.getElementById('left-val-badge');

    const rightFreqInput = document.getElementById('right-freq');
    const rightFreqVal = document.getElementById('right-freq-val');
    const rightGainInput = document.getElementById('right-gain');
    const rightGainVal = document.getElementById('right-gain-val');
    const rightValBadge = document.getElementById('right-val-badge');

    leftFreqInput.addEventListener('input', (e) => {
        val = parseInt(e.target.value);
        state.audio.leftFreq = val;
        leftFreqVal.textContent = val + ' Hz';
        leftValBadge.textContent = val + ' Hz';
        if (state.audio.leftOsc && state.audio.context) {
            state.audio.leftOsc.frequency.setValueAtTime(val, state.audio.context.currentTime);
        }
    });

    leftGainInput.addEventListener('input', (e) => {
        val = parseFloat(e.target.value);
        state.audio.leftGainVal = val;
        leftGainVal.textContent = Math.round(val * 100) + '%';
        if (state.audio.leftGain && state.audio.context && state.audio.isPlaying) {
            state.audio.leftGain.gain.setValueAtTime(val * 0.3, state.audio.context.currentTime);
        }
    });

    rightFreqInput.addEventListener('input', (e) => {
        val = parseInt(e.target.value);
        state.audio.rightFreq = val;
        rightFreqVal.textContent = val + ' Hz';
        rightValBadge.textContent = val + ' Hz';
        if (state.audio.rightOsc && state.audio.context) {
            state.audio.rightOsc.frequency.setValueAtTime(val, state.audio.context.currentTime);
        }
    });

    rightGainInput.addEventListener('input', (e) => {
        val = parseFloat(e.target.value);
        state.audio.rightGainVal = val;
        rightGainVal.textContent = Math.round(val * 100) + '%';
        if (state.audio.rightGain && state.audio.context && state.audio.isPlaying) {
            state.audio.rightGain.gain.setValueAtTime(val * 0.3, state.audio.context.currentTime);
        }
    });

    // Waveform radio chips
    document.querySelectorAll('#left-waveform .radio-chip').forEach(chip => {
        chip.addEventListener('click', () => {
            document.querySelectorAll('#left-waveform .radio-chip').forEach(c => c.classList.remove('active'));
            chip.classList.add('active');
            const radio = chip.querySelector('input');
            radio.checked = true;
            state.audio.leftWave = radio.value;
            if (state.audio.leftOsc) state.audio.leftOsc.type = radio.value;
            logEvent(`Left actuator waveform updated to: ${radio.value}`);
        });
    });

    document.querySelectorAll('#right-waveform .radio-chip').forEach(chip => {
        chip.addEventListener('click', () => {
            document.querySelectorAll('#right-waveform .radio-chip').forEach(c => c.classList.remove('active'));
            chip.classList.add('active');
            const radio = chip.querySelector('input');
            radio.checked = true;
            state.audio.rightWave = radio.value;
            if (state.audio.rightOsc) state.audio.rightOsc.type = radio.value;
            logEvent(`Right actuator waveform updated to: ${radio.value}`);
        });
    });

    // Burst pulse button
    document.getElementById('trigger-rumble-test').addEventListener('click', () => {
        if (!state.audio.context) initAudioEngine();
        if (state.audio.context.state === 'suspended') state.audio.context.resume();
        
        const now = state.audio.context.currentTime;
        state.audio.leftGain.gain.setValueAtTime(0.9, now);
        state.audio.leftGain.gain.exponentialRampToValueAtTime(0.001, now + 0.4);
        state.audio.rightGain.gain.setValueAtTime(0.9, now);
        state.audio.rightGain.gain.exponentialRampToValueAtTime(0.001, now + 0.4);
        logEvent("Executed high-energy haptic burst pulse (400ms).", "success");
    });

    // --- CANVAS OSCILLOSCOPE ---
    const rumbleCanvas = document.getElementById('rumbleCanvas');
    const rumbleCtx = rumbleCanvas ? rumbleCanvas.getContext('2d') : null;

    function resizeCanvas(canvas) {
        if (!canvas) return;
        const rect = canvas.getBoundingClientRect();
        canvas.width = rect.width * window.devicePixelRatio;
        canvas.height = rect.height * window.devicePixelRatio;
        const ctx = canvas.getContext('2d');
        ctx.scale(window.devicePixelRatio, window.devicePixelRatio);
    }

    window.addEventListener('resize', () => {
        resizeCanvas(rumbleCanvas);
        resizeCanvas(triggerCanvas);
    });

    if (rumbleCanvas) resizeCanvas(rumbleCanvas);

    function drawOscilloscope() {
        requestAnimationFrame(drawOscilloscope);
        if (!rumbleCtx || !rumbleCanvas) return;

        const width = rumbleCanvas.width / window.devicePixelRatio;
        const height = rumbleCanvas.height / window.devicePixelRatio;

        rumbleCtx.fillStyle = '#0b0f19';
        rumbleCtx.fillRect(0, 0, width, height);

        // Draw grid lines
        rumbleCtx.strokeStyle = '#1f2937';
        rumbleCtx.lineWidth = 1;
        for (let x = 0; x < width; x += 40) {
            rumbleCtx.beginPath();
            rumbleCtx.moveTo(x, 0);
            rumbleCtx.lineTo(x, height);
            rumbleCtx.stroke();
        }
        for (let y = 0; y < height; y += 40) {
            rumbleCtx.beginPath();
            rumbleCtx.moveTo(0, y);
            rumbleCtx.lineTo(width, y);
            rumbleCtx.stroke();
        }

        if (state.audio.analyser && state.audio.isPlaying) {
            const bufferLength = state.audio.analyser.frequencyBinCount;
            const dataArray = new Uint8Array(bufferLength);
            state.audio.analyser.getByteTimeDomainData(dataArray);

            rumbleCtx.lineWidth = 2;
            rumbleCtx.strokeStyle = '#3b82f6';
            rumbleCtx.beginPath();

            const sliceWidth = width / bufferLength;
            let x = 0;

            for (let i = 0; i < bufferLength; i++) {
                const v = dataArray[i] / 128.0;
                const y = v * (height / 2);

                if (i === 0) rumbleCtx.moveTo(x, y);
                else rumbleCtx.lineTo(x, y);

                x += sliceWidth;
            }
            rumbleCtx.stroke();
        } else {
            // Simulated waveform when idle
            rumbleCtx.lineWidth = 2;
            rumbleCtx.strokeStyle = '#374151';
            rumbleCtx.beginPath();
            for (let x = 0; x < width; x++) {
                const y = height / 2 + Math.sin(x * 0.02 + Date.now() * 0.005) * 15 * state.audio.leftGainVal;
                if (x === 0) rumbleCtx.moveTo(x, y);
                else rumbleCtx.lineTo(x, y);
            }
            rumbleCtx.stroke();
        }
    }
    if (rumbleCanvas) drawOscilloscope();


    // --- ADAPTIVE TRIGGER MODULE & VISUALIZER ---
    const triggerCanvas = document.getElementById('triggerCanvas');
    const triggerCtx = triggerCanvas ? triggerCanvas.getContext('2d') : null;
    if (triggerCanvas) resizeCanvas(triggerCanvas);

    const triggerModeSelect = document.getElementById('trigger-mode');
    const triggerStartInput = document.getElementById('trigger-start');
    const triggerStartVal = document.getElementById('trigger-start-val');
    const triggerEndInput = document.getElementById('trigger-end');
    const triggerEndVal = document.getElementById('trigger-end-val');
    const triggerStrengthInput = document.getElementById('trigger-strength');
    const triggerStrengthVal = document.getElementById('trigger-strength-val');
    const triggerPullDepth = document.getElementById('trigger-pull-depth');
    const pullDepthVal = document.getElementById('pull-depth-val');
    const activeModeBadge = document.getElementById('active-mode-badge');

    // Segmented channel buttons
    document.querySelectorAll('#trigger-channel-select .seg-btn').forEach(btn => {
        btn.addEventListener('click', () => {
            document.querySelectorAll('#trigger-channel-select .seg-btn').forEach(b => b.classList.remove('active'));
            btn.classList.add('active');
            state.triggers.channel = btn.getAttribute('data-channel');
            logEvent(`Target trigger channel changed to: ${state.triggers.channel.toUpperCase()}`);
        });
    });

    triggerModeSelect.addEventListener('change', (e) => {
        state.triggers.mode = e.target.value;
        activeModeBadge.textContent = triggerModeSelect.options[triggerModeSelect.selectedIndex].text;
        logEvent(`Trigger effect mode updated: ${state.triggers.mode}`);
    });

    triggerStartInput.addEventListener('input', (e) => {
        state.triggers.startPos = parseInt(e.target.value);
        triggerStartVal.textContent = `${state.triggers.startPos} / 9`;
    });

    triggerEndInput.addEventListener('input', (e) => {
        state.triggers.endPos = parseInt(e.target.value);
        triggerEndVal.textContent = `${state.triggers.endPos} / 9`;
    });

    triggerStrengthInput.addEventListener('input', (e) => {
        state.triggers.strength = parseInt(e.target.value);
        triggerStrengthVal.textContent = `Level ${state.triggers.strength}`;
    });

    triggerPullDepth.addEventListener('input', (e) => {
        state.triggers.pullDepth = parseInt(e.target.value);
        pullDepthVal.textContent = `${state.triggers.pullDepth}%`;
    });

    function drawTriggerVisualizer() {
        requestAnimationFrame(drawTriggerVisualizer);
        if (!triggerCtx || !triggerCanvas) return;

        const width = triggerCanvas.width / window.devicePixelRatio;
        const height = triggerCanvas.height / window.devicePixelRatio;

        triggerCtx.fillStyle = '#0b0f19';
        triggerCtx.fillRect(0, 0, width, height);

        // Draw grid
        triggerCtx.strokeStyle = '#1f2937';
        triggerCtx.lineWidth = 1;
        for (let x = 0; x < width; x += 50) {
            triggerCtx.beginPath(); triggerCtx.moveTo(x, 0); triggerCtx.lineTo(x, height); triggerCtx.stroke();
        }
        for (let y = 0; y < height; y += 40) {
            triggerCtx.beginPath(); triggerCtx.moveTo(0, y); triggerCtx.lineTo(width, y); triggerCtx.stroke();
        }

        // Draw axes labels
        triggerCtx.fillStyle = '#9ca3af';
        triggerCtx.font = '11px JetBrains Mono';
        triggerCtx.fillText('0% (Free)', 20, height - 10);
        triggerCtx.fillText('100% (Fully Depressed)', width - 160, height - 10);
        triggerCtx.fillText('Max Resistance', 20, 25);

        // Draw Resistance Curve based on mode
        triggerCtx.beginPath();
        triggerCtx.strokeStyle = '#06b6d4';
        triggerCtx.lineWidth = 3;

        const startX = 60;
        const endX = width - 60;
        const graphHeight = height - 80;
        const baselineY = height - 40;

        triggerCtx.moveTo(startX, baselineY);

        for (let px = startX; px <= endX; px++) {
            const progress = (px - startX) / (endX - startX); // 0 to 1
            let resistanceY = baselineY;

            const startThreshold = state.triggers.startPos / 9.0;
            const endThreshold = state.triggers.endPos / 9.0;
            const strengthFactor = state.triggers.strength / 8.0;

            if (state.triggers.mode === 'feedback') {
                if (progress >= startThreshold && progress <= endThreshold) {
                    resistanceY = baselineY - (graphHeight * strengthFactor * 0.7);
                } else if (progress > endThreshold) {
                    resistanceY = baselineY - (graphHeight * strengthFactor * 0.3);
                }
            } else if (state.triggers.mode === 'weapon') {
                if (progress >= startThreshold && progress <= startThreshold + 0.1) {
                    resistanceY = baselineY - (graphHeight * strengthFactor); // Resistance wall
                } else if (progress > startThreshold + 0.1) {
                    resistanceY = baselineY - (graphHeight * 0.1); // Break / snap
                }
            } else if (state.triggers.mode === 'vibration') {
                if (progress >= startThreshold && progress <= endThreshold) {
                    const rumbleWave = Math.sin(progress * 40) * (graphHeight * 0.15 * strengthFactor);
                    resistanceY = baselineY - (graphHeight * strengthFactor * 0.5) + rumbleWave;
                }
            } else if (state.triggers.mode === 'slope') {
                if (progress >= startThreshold) {
                    const slopeProgress = (progress - startThreshold) / (1 - startThreshold);
                    resistanceY = baselineY - (graphHeight * strengthFactor * slopeProgress);
                }
            } else {
                // Off / standard spring
                resistanceY = baselineY - (graphHeight * 0.1 * progress);
            }

            triggerCtx.lineTo(px, resistanceY);
        }
        triggerCtx.stroke();

        // Draw current finger pull depth indicator
        const currentX = startX + (state.triggers.pullDepth / 100.0) * (endX - startX);
        triggerCtx.strokeStyle = '#ec4899';
        triggerCtx.lineWidth = 2;
        triggerCtx.setLineDash([4, 4]);
        triggerCtx.beginPath();
        triggerCtx.moveTo(currentX, 20);
        triggerCtx.lineTo(currentX, baselineY);
        triggerCtx.stroke();
        triggerCtx.setLineDash([]);

        // Finger indicator circle
        triggerCtx.fillStyle = '#ec4899';
        triggerCtx.beginPath();
        triggerCtx.arc(currentX, baselineY - 40, 6, 0, Math.PI * 2);
        triggerCtx.fill();
    }
    if (triggerCanvas) drawTriggerVisualizer();


    // --- PRESETS LOADING ---
    const presetsData = {
        'heavy-rain': { lFreq: 60, lGain: 0.4, rFreq: 320, rGain: 0.7, tMode: 'off', tStart: 2, tEnd: 8, tStr: 3 },
        'shotgun': { lFreq: 110, lGain: 0.9, rFreq: 220, rGain: 0.8, tMode: 'weapon', tStart: 6, tEnd: 9, tStr: 8 },
        'sports-car': { lFreq: 85, lGain: 0.8, rFreq: 190, rGain: 0.6, tMode: 'feedback', tStart: 3, tEnd: 8, tStr: 6 },
        'heartbeat': { lFreq: 45, lGain: 0.95, rFreq: 120, rGain: 0.3, tMode: 'slope', tStart: 1, tEnd: 9, tStr: 7 },
        'sword-clash': { lFreq: 150, lGain: 1.0, rFreq: 450, rGain: 0.9, tMode: 'feedback', tStart: 1, tEnd: 5, tStr: 8 },
        'ice-surface': { lFreq: 200, lGain: 0.5, rFreq: 520, rGain: 0.75, tMode: 'vibration', tStart: 2, tEnd: 8, tStr: 4 }
    };

    document.querySelectorAll('.load-preset-btn').forEach(btn => {
        btn.addEventListener('click', (e) => {
            const card = e.target.closest('.preset-card');
            const presetKey = card.getAttribute('data-preset');
            const data = presetsData[presetKey];
            if (!data) return;

            // Apply to state
            state.audio.leftFreq = data.lFreq;
            state.audio.leftGainVal = data.lGain;
            state.audio.rightFreq = data.rFreq;
            state.audio.rightGainVal = data.rGain;
            state.triggers.mode = data.tMode;
            state.triggers.startPos = data.tStart;
            state.triggers.endPos = data.tEnd;
            state.triggers.strength = data.tStr;

            // Update DOM inputs
            leftFreqInput.value = data.lFreq; leftFreqVal.textContent = data.lFreq + ' Hz'; leftValBadge.textContent = data.lFreq + ' Hz';
            leftGainInput.value = data.lGain; leftGainVal.textContent = Math.round(data.lGain * 100) + '%';
            rightFreqInput.value = data.rFreq; rightFreqVal.textContent = data.rFreq + ' Hz'; rightValBadge.textContent = data.rFreq + ' Hz';
            rightGainInput.value = data.rGain; rightGainVal.textContent = Math.round(data.rGain * 100) + '%';
            triggerModeSelect.value = data.tMode;
            activeModeBadge.textContent = triggerModeSelect.options[triggerModeSelect.selectedIndex].text;
            triggerStartInput.value = data.tStart; triggerStartVal.textContent = `${data.tStart} / 9`;
            triggerEndInput.value = data.tEnd; triggerEndVal.textContent = `${data.end} / 9`;
            triggerStrengthInput.value = data.tStr; triggerStrengthVal.textContent = `Level ${data.tStr}`;

            if (state.audio.context && state.audio.isPlaying) {
                const now = state.audio.context.currentTime;
                state.audio.leftOsc.frequency.setValueAtTime(data.lFreq, now);
                state.audio.rightOsc.frequency.setValueAtTime(data.rFreq, now);
                state.audio.leftGain.gain.setValueAtTime(data.lGain * 0.3, now);
                state.audio.rightGain.gain.setValueAtTime(data.rGain * 0.3, now);
            }

            logEvent(`Loaded haptic preset: ${card.querySelector('h3').textContent}`, "success");
            
            // Switch to rumble tab to show effect
            document.querySelector('[data-tab="rumble"]').click();
        });
    });

    // --- JSON EXPORT MODAL ---
    const exportModal = document.getElementById('export-modal');
    const exportBtn = document.getElementById('export-preset-btn');
    const closeModalBtn = document.querySelector('.close-modal');
    const jsonOutput = document.getElementById('json-export-output');
    const copyJsonBtn = document.getElementById('copy-json-btn');
    const downloadJsonBtn = document.getElementById('download-json-btn');

    if (exportBtn) {
        exportBtn.addEventListener('click', () => {
            const exportData = {
                metadata: {
                    generator: "DualSense Haptics Lab v2.4",
                    timestamp: new Date().toISOString()
                },
                actuators: {
                    left: { frequency: state.audio.leftFreq, gain: state.audio.leftGainVal, waveform: state.audio.leftWave },
                    right: { frequency: state.audio.rightFreq, gain: state.audio.rightGainVal, waveform: state.audio.rightWave }
                },
                adaptiveTrigger: {
                    channel: state.triggers.channel,
                    mode: state.triggers.mode,
                    startPosition: state.triggers.startPos,
                    endPosition: state.triggers.endPos,
                    forceStrength: state.triggers.strength
                }
            };
            jsonOutput.value = JSON.stringify(exportData, null, 4);
            exportModal.style.display = 'flex';
            logEvent("Generated DualSense JSON haptic profile export.");
        });
    }

    if (closeModalBtn) {
        closeModalBtn.addEventListener('click', () => { exportModal.style.display = 'none'; });
    }

    if (copyJsonBtn) {
        copyJsonBtn.addEventListener('click', () => {
            navigator.clipboard.writeText(jsonOutput.value);
            copyJsonBtn.innerHTML = `<i class="fa-solid fa-check"></i> Copied!`;
            setTimeout(() => { copyJsonBtn.innerHTML = `<i class="fa-solid fa-copy"></i> Copy to Clipboard`; }, 2000);
            logEvent("Copied haptic JSON configuration to clipboard.", "success");
        });
    }

    if (downloadJsonBtn) {
        downloadJsonBtn.addEventListener('click', () => {
            const blob = new Blob([jsonOutput.value], { type: 'application/json' });
            const url = URL.createObjectURL(blob);
            const a = document.createElement('a');
            a.href = url;
            a.download = `dualsense-haptic-profile-${Date.now()}.json`;
            a.click();
            URL.revokeObjectURL(url);
            logEvent("Downloaded haptic JSON file.", "success");
        });
    }

    logEvent("DualSense Haptics Lab application mounted successfully.");
});
