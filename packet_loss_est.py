def estimate_packet_loss(received, expected):
    return max(0.0, 1.0 - (received / max(expected, 1)))
