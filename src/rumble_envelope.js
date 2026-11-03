// DualSense Rumble Envelope Shaper (Attack, Decay, Sustain, Release)
export class RumbleEnvelope {
    constructor(attackMs = 20, decayMs = 50, sustainLevel = 0.7, releaseMs = 100) {
        this.a = attackMs / 1000;
        this.d = decayMs / 1000;
        this.s = sustainLevel;
        this.r = releaseMs / 1000;
    }

    apply(gainNode, startTime, peakGain = 1.0) {
        const p = gainNode.gain;
        p.cancelScheduledValues(startTime);
        p.setValueAtTime(0, startTime);
        p.linearRampToValueAtTime(peakGain, startTime + this.a);
        p.linearRampToValueAtTime(peakGain * this.s, startTime + this.a + this.d);
    }
}
