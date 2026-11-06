#pragma once
#include <cmath>

namespace dualsense {
struct LightbarExponentialEasing {
    static constexpr float ease_in_out(float t) noexcept {
        if (t <= 0.0f) return 0.0f;
        if (t >= 1.0f) return 1.0f;
        return (t < 0.5f) ? (2.0f * t * t) : (-1.0f + (4.0f - 2.0f * t) * t);
    }
};
}
