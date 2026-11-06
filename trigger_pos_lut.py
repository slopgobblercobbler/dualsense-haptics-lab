def compute_trigger_pos_lut(steps=256):
    return {i: (i / 255.0) ** 1.2 for i in range(steps)}
