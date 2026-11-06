#pragma once
#include <cmath>

namespace dualsense {
struct AccelShockDetector {
    static bool isShock(float ax, float ay, float az, float thresholdG = 4.0f) {
        float mag = std::sqrt(ax * ax + ay * ay + az * az);
        return mag >= thresholdG;
    }
};
}
