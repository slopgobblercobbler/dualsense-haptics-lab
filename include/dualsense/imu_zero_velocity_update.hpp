#pragma once
#include <cmath>

namespace dualsense {
struct ZeroVelocityDetector {
    static bool isStationary(float ax, float ay, float az, float gx, float gy, float gz,
                            float accelThreshold = 0.08f, float gyroThreshold = 0.03f) {
        float aMag = std::abs(std::sqrt(ax * ax + ay * ay + az * az) - 1.0f);
        float gMag = std::sqrt(gx * gx + gy * gy + gz * gz);
        return (aMag < accelThreshold) && (gMag < gyroThreshold);
    }
};
}
