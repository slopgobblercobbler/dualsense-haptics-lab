def is_edge_contact(x, y, margin=15, max_x=1920, max_y=1080):
    return x < margin or x > (max_x - margin) or y < margin or y > (max_y - margin)
