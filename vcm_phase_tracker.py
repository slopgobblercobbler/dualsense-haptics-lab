def track_vcm_phase(current, voltage):
    return {'phase_lead': voltage > current, 'diff': abs(voltage - current)}
