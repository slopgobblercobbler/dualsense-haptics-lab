
def generate_burst(frequency_hz: float, duration_ms: float) -> bytes:
    return bytes([0xAA, int(frequency_hz) & 0xFF, int(duration_ms) & 0xFF])
