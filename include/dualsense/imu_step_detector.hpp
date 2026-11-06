#pragma once
#include <cmath>

namespace dualsense {
struct ImuStepDetector {
    float prev_accel_norm{1.0f};
    bool step_detected{false};
    bool update(float ax, float ay, float az, float threshold) noexcept {
        const float norm = std::hypot(ax, ay, az);
        step_detected = (prev_accel_norm > threshold && norm <= threshold);
        prev_accel_norm = norm;
        return step_detected;
    }
};
}
