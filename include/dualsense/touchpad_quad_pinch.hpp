#pragma once
#include <cmath>

namespace dualsense {
struct TouchpadQuadPinch {
    static constexpr float pinch_threshold = 50.0f;
    static bool is_pinch_in(float initial_spread, float current_spread) noexcept {
        return (initial_spread - current_spread) >= pinch_threshold;
    }
};
}
