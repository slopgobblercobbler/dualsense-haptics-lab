# DualSense Adaptive Trigger Tuning Guide

## Modes
- **Mode 0 (Off)**: No active force applied to the trigger.
- **Mode 1 (Feedback)**: Linear resistance starting at `startPosition` up to `endPosition`.
- **Mode 2 (Weapon / Recoil)**: Two-stage sharp click simulating gun trigger breaking force.
- **Mode 3 (Vibration)**: Motor oscillates at specified `frequency` (0..40 Hz) with configured `strength`.

## Safety Constraints
- Frequency values must strictly stay within 0..40 Hz to prevent mechanical actuator wear.
- Force levels must stay in range 0..10.
