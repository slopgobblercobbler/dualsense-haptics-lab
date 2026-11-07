def compute_pinch_distance(p1, p2):
    import math
    return math.hypot(p2[0] - p1[0], p2[1] - p1[1])
