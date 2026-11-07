def compute_touch_aspect_ratio(major_axis, minor_axis):
    return major_axis / max(minor_axis, 1e-4)
