#pragma once
#include <algorithm>

namespace dualsense {
struct TouchpadInertiaDecay {
    float vx{0.0f};
    float vy{0.0f};
    void update(float friction_factor) noexcept {
        vx *= friction_factor;
        vy *= friction_factor;
        if (std::abs(vx) < 0.01f) vx = 0.0f;
        if (std::abs(vy) < 0.01f) vy = 0.0f;
    }
};
}
