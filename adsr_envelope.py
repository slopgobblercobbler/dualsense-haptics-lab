def compute_adsr(a, d, s, r, t, duration):
    if t < a: return t / a
    elif t < a + d: return 1.0 - (1.0 - s) * ((t - a) / d)
    elif t < duration - r: return s
    else: return max(0.0, s * (1.0 - (t - (duration - r)) / r))
