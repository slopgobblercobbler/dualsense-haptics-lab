def detect_pinch(p1, p2, prev_dist):
    import math
    d = math.hypot(p1[0] - p2[0], p1[1] - p2[1])
    return d - prev_dist
