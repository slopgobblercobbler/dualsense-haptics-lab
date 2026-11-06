def estimate_slope_velocity(prev_pos, curr_pos, dt):
    return (curr_pos - prev_pos) / max(dt, 1e-6)
