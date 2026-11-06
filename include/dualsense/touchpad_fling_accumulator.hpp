#pragma once
#include <cmath>

namespace dualsense {
struct TouchpadFlingAccumulator {
    float accumulated_dist{0.0f};
    void add_sample(float dx, float dy) noexcept {
        accumulated_dist += std::hypot(dx, dy);
    }
    void reset() noexcept {
        accumulated_dist = 0.0f;
    }
};
}
