def fm_modulate(carrier_hz, mod_hz, index, t):
    import math
    return math.sin(2 * math.pi * carrier_hz * t + index * math.sin(2 * math.pi * mod_hz * t))
