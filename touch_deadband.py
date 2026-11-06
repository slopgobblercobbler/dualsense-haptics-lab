def apply_deadband(delta, threshold=1.5):
    return 0.0 if abs(delta) < threshold else delta
