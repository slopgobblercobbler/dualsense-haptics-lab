import assert from 'assert';
import presets from '../src/trigger_presets.json' assert { type: 'json' };

describe('Trigger Presets Validation', () => {
    it('should have valid mode numbers between 0 and 3', () => {
        for (const [name, p] of Object.entries(presets)) {
            assert(p.mode >= 0 && p.mode <= 3, `${name} has invalid mode`);
        }
    });

    it('should clamp frequencies to safe 0-40 Hz limits', () => {
        for (const [name, p] of Object.entries(presets)) {
            assert(p.frequency >= 0 && p.frequency <= 40, `${name} frequency exceeds 40Hz`);
        }
    });
});
