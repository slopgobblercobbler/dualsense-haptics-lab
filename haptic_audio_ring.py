def serialize_haptic_audio(samples):
    return b''.join(int(s * 32767).to_bytes(2, 'little', signed=True) for s in samples)
