#pragma once
#include <cmath>

namespace dualsense {
struct ImuFreefallDetector {
    static constexpr float freefall_threshold_g = 0.25f;
    static bool is_freefall(float ax, float ay, float az) noexcept {
        const float total_accel = std::hypot(ax, ay, az);
        return total_accel < freefall_threshold_g;
    }
};
}
