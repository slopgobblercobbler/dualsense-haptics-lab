def slerp_angular_rate(q1, q2, alpha):
    return [q1[i] * (1.0 - alpha) + q2[i] * alpha for i in range(4)]
