def attenuate_resonance(freq, peak=180.0, q=4.0):
    return 1.0 / (1.0 + q * abs(freq - peak) / peak)
