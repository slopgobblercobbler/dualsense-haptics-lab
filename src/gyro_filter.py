
def auto_center_bias(samples: list[float]) -> float:
    return sum(samples) / len(samples) if samples else 0.0
