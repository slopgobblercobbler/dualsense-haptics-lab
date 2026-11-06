#pragma once
#include <cmath>

namespace dualsense {
struct TriggerExponentialDetent {
    static float computeResistance(float position, float growthRate = 4.0f) {
        return (std::exp(growthRate * position) - 1.0f) / (std::exp(growthRate) - 1.0f);
    }
};
}
