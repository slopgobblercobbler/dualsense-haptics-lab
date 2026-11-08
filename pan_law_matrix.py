def compute_pan_gains(pan_norm):
    import math
    angle = pan_norm * (math.pi / 4.0)
    return (math.cos(angle), math.sin(angle))
