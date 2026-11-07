def apply_rgb_gamma(color, gamma=2.2):
    return [pow(c / 255.0, gamma) * 255.0 for c in color]
