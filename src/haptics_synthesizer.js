// DualSense Web Audio synthesized haptic rumble waveform generator
export class HapticsSynthesizer {
    constructor(audioContext) {
        this.ctx = audioContext || new (window.AudioContext || window.webkitAudioContext)();
    }

    createRumbleNode(frequency = 120, amplitude = 0.8, type = 'sine') {
        const osc = this.ctx.createOscillator();
        const gain = this.ctx.createGain();
        osc.type = type;
        osc.frequency.setValueAtTime(frequency, this.ctx.currentTime);
        gain.gain.setValueAtTime(amplitude, this.ctx.currentTime);
        osc.connect(gain);
        return { oscillator: osc, gainNode: gain };
    }

    playBurst(durationMs = 150, frequency = 160) {
        const { oscillator, gainNode } = this.createRumbleNode(frequency, 0.9, 'triangle');
        gainNode.connect(this.ctx.destination);
        oscillator.start();
        oscillator.stop(this.ctx.currentTime + (durationMs / 1000));
    }
}
