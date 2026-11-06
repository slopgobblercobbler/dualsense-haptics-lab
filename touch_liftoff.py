def extrapolate_liftoff(x_coords, y_coords):
    dx = x_coords[-1] - x_coords[-2] if len(x_coords) > 1 else 0
    dy = y_coords[-1] - y_coords[-2] if len(y_coords) > 1 else 0
    return (x_coords[-1] + dx * 0.5, y_coords[-1] + dy * 0.5)
