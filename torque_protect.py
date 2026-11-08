def check_stall_torque(duty_cycle, duration_ms):
    return duty_cycle if duration_ms < 500 else min(duty_cycle, 0.4)
