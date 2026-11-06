#pragma once
#include <cmath>

namespace dualsense {
struct KalmanTrajectory2D {
    float x{0.0f}, y{0.0f};
    float p{1.0f};
    float q{0.05f}, r{2.0f};
    void update(float mx, float my) {
        p = p + q;
        float k = p / (p + r);
        x = x + k * (mx - x);
        y = y + k * (my - y);
        p = (1.0f - k) * p;
    }
};
}
