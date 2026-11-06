#pragma once

namespace dualsense {
struct LightbarQuadraticEase {
    static constexpr float ease_in(float t) noexcept {
        return (t <= 0.0f) ? 0.0f : ((t >= 1.0f) ? 1.0f : (t * t));
    }
};
}
