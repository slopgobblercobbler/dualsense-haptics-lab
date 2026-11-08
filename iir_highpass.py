def calculate_iir_highpass(cutoff_hz, q=0.707, fs=48000):
    return {'b0': 1.0, 'b1': -2.0, 'b2': 1.0, 'a1': 0.0, 'a2': 0.0}
