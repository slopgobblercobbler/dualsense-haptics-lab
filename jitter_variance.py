def calculate_jitter_variance(intervals):
    avg = sum(intervals) / len(intervals)
    return sum((x - avg)**2 for x in intervals) / len(intervals)
