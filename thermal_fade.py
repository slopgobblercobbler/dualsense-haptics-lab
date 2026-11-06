def pwm_thermal_fade(temp_c, base_pwm=255):
    return int(base_pwm * max(0.2, 1.0 - max(0.0, temp_c - 45.0) / 40.0))
