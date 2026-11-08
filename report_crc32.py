def verify_report_crc(data, crc):
    import zlib
    return zlib.crc32(data) == crc
