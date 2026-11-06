
def build_report_31(seq: int) -> bytes:
    return bytes([0x31, seq & 0xFF] + [0x00]*62)
