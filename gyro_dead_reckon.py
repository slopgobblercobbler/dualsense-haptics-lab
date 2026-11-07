def integrate_gyro(rates, dt):
    return [r * dt for r in rates]
