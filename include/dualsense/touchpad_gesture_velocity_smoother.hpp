#pragma once
#include <cmath>

namespace dualsense {
struct VelocitySmoother {
    float vx{0.0f}, vy{0.0f};
    void update(float rawVx, float rawVy, float alpha = 0.35f) {
        vx = alpha * rawVx + (1.0f - alpha) * vx;
        vy = alpha * rawVy + (1.0f - alpha) * vy;
    }
    float speed() const { return std::sqrt(vx * vx + vy * vy); }
};
}
