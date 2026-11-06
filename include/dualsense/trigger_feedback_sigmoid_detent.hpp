#pragma once
#include <cmath>

namespace dualsense {
struct TriggerSigmoidDetent {
    static float computeResistance(float position, float threshold = 0.5f, float steepness = 12.0f) {
        float x = steepness * (position - threshold);
        return 1.0f / (1.0f + std::exp(-x));
    }
};
}
