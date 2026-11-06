#pragma once
#include <algorithm>

namespace dualsense {
struct DualMotorBalance {
    static void balance(float intensity, float pan, float& leftMotor, float& rightMotor) {
        float clampedPan = std::clamp(pan, -1.0f, 1.0f);
        leftMotor = intensity * std::clamp(1.0f - clampedPan, 0.0f, 1.0f);
        rightMotor = intensity * std::clamp(1.0f + clampedPan, 0.0f, 1.0f);
    }
};
}
