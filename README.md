# DualSense Haptics Lab 🎮⚡

> Advanced haptic force feedback synthesizer and adaptive trigger calibration laboratory designed for PlayStation 5 developers, audio engineers, and hardware enthusiasts.

[![Deploy to GitHub Pages](https://github.com/slopgobblercobbler/dualsense-haptics-lab/actions/workflows/deploy-pages.yml/badge.svg)](https://github.com/slopgobblercobbler/dualsense-haptics-lab/actions/workflows/deploy-pages.yml)
[![License: MIT](https://img.shields.io/badge/License-MIT-blue.svg)](LICENSE)

**Live Demo:** [https://slopgobblercobbler.github.io/dualsense-haptics-lab/](https://slopgobblercobbler.github.io/dualsense-haptics-lab/)

---

## 🌟 Overview

**DualSense Haptics Lab** is a high-utility, dark-mode single-page interactive web application designed to simulate, visualize, and test PlayStation 5 DualSense controller haptics and adaptive triggers directly in the browser using the **Web Audio API** and **HTML5 Canvas**.

### ✨ Key Features

1. **Voice Coil Actuators & Dual-Motor Rumble Synthesizer**
   - Independent frequency (Hz) and gain control for Left (heavy sub-bass) and Right (crisp mid/high texture) voice coils.
   - Multiple waveform generators (Sine, Triangle, Sawtooth, Square).
   - Real-time HTML5 canvas oscilloscope displaying combined haptic waveforms.
   - High-energy burst pulse testing.

2. **Adaptive Trigger Resistance & Effect Curve Visualizer**
   - Multi-mode support: **Feedback** (constant resistance), **Weapon** (trigger break/pull resistance wall), **Vibration** (rapid pulsing), and **Slope Feedback** (progressive).
   - Adjustable start position, end position, and force strength levels (0-10).
   - Real-time finger pull-depth simulation with instant resistance curve recalculation.

3. **PlayStation Studio Haptic Presets**
   - Instantly load battle-tested haptic profiles: *Ambient Heavy Rain*, *Shotgun Trigger Break*, *Supercar Throttle*, *Adrenaline Heartbeat*, *Melee Sword Parry*, and *Glacial Ice Skating*.

4. **Real-time Telemetry & Performance Monitor**
   - Live sample rate inspection, audio buffer latency metrics, thermal load estimates for voice coils and driver ICs, and event terminal logs.
   - JSON export and clipboard copy for game engine integration (Unreal, Unity, and custom C++ pipelines).

---

## 🚀 Quick Start & Development

Clone the repository and open `index.html` in any modern web browser, or serve locally via a static file server:

```bash
git clone https://github.com/slopgobblercobbler/dualsense-haptics-lab.git
cd dualsense-haptics-lab
# Serve locally (e.g. Python or Node)
python -m http.server 8000
```

---

## 📄 License

Distributed under the **MIT License**. See [LICENSE](LICENSE) for more information.
