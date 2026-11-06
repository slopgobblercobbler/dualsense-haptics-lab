#pragma once
#include <cstdint>
#include <cmath>

namespace dualsense {
struct TouchpadPinchDetector {
    static float compute_finger_distance(std::int16_t x1, std::int16_t y1, std::int16_t x2, std::int16_t y2) noexcept {
        const float dx = static_cast<float>(x2 - x1);
        const float dy = static_cast<float>(y2 - y1);
        return std::hypot(dx, dy);
    }
};
}
