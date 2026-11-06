def compensate_gravity(accel, gravity=(0.0, 0.0, 9.81)):
    return [accel[i] - gravity[i] for i in range(3)]
