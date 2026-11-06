#pragma once
#include <cmath>

namespace dualsense {
struct GyroThresholdTrigger {
    static bool isSpike(float gx, float gy, float gz, float thresholdRadPerSec = 5.0f) {
        float magnitudeSq = gx * gx + gy * gy + gz * gz;
        return magnitudeSq >= (thresholdRadPerSec * thresholdRadPerSec);
    }
};
}
