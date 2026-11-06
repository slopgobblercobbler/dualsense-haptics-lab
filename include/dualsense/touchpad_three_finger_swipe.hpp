#pragma once
#include <cmath>
#include <string_view>

namespace dualsense {
struct ThreeFingerSwipeDetector {
    static std::string_view classify(float dx, float dy, float threshold = 50.0f) {
        if (std::abs(dx) > std::abs(dy) && std::abs(dx) >= threshold) {
            return dx > 0.0f ? "SWIPE_RIGHT" : "SWIPE_LEFT";
        } else if (std::abs(dy) >= threshold) {
            return dy > 0.0f ? "SWIPE_DOWN" : "SWIPE_UP";
        }
        return "NONE";
    }
};
}
