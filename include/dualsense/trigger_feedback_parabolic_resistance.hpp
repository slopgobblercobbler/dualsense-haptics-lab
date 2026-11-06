#pragma once
#include <cmath>

namespace dualsense {
struct TriggerParabolicResistance {
    static float computeResistance(float position, float curvature = 2.0f) {
        float p = std::clamp(position, 0.0f, 1.0f);
        return std::pow(p, curvature);
    }
};
}
