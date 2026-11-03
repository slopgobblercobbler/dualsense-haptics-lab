// DualSense Battery and Power State Decoder
export class BatteryDecoder {
    static decode(rawByte) {
        const level = (rawByte & 0x0f) * 10;
        const charging = (rawByte & 0x10) !== 0;
        const fullyCharged = (rawByte & 0x20) !== 0;
        return {
            percentage: Math.min(100, level),
            charging,
            fullyCharged
        };
    }
}
