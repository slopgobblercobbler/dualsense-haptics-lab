
def downsample_pcm(data: bytes, factor: int) -> bytes:
    return data[::factor]
