def filter_back_emf(voltage, current, ke=0.05):
    return max(0.0, voltage - current * ke)
