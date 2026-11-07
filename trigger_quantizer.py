def quantize_trigger_pos(val, bits=8):
    step = 1.0 / ((1 << bits) - 1)
    return round(val / step) * step
