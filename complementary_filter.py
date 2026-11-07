def complementary_filter(gyro_angle, accel_angle, alpha=0.98):
    return alpha * gyro_angle + (1.0 - alpha) * accel_angle
