
def calibrate_wear(raw_val: int, wear_offset: int) -> int:
    return max(0, min(255, raw_val - wear_offset))
