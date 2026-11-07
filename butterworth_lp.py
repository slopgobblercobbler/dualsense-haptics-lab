def butterworth_4th_lp(cutoff_hz, sample_rate=48000):
    return {'type': 'butterworth_4th', 'cutoff': cutoff_hz, 'rate': sample_rate}
