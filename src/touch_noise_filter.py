
def median_filter(points: list[int]) -> int:
    s = sorted(points)
    return s[len(s)//2] if s else 0
