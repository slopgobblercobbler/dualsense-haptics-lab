import assert from 'assert';
import colors from '../src/lightbar_colors.json' assert { type: 'json' };

describe('Lightbar Colors', () => {
    it('should have valid RGB ranges (0-255)', () => {
        for (const [name, c] of Object.entries(colors)) {
            assert(c.r >= 0 && c.r <= 255);
            assert(c.g >= 0 && c.g <= 255);
            assert(c.b >= 0 && c.b <= 255);
        }
    });
});
