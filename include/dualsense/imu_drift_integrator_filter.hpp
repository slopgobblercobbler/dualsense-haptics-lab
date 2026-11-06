#pragma once
#include <cmath>

namespace dualsense {
struct ImuDriftCompensator {
    float estimatedBias{0.0f};
    float filterRate(float rawRate, float biasAdaptRate = 0.001f) {
        if (std::abs(rawRate) < 0.05f) {
            estimatedBias += biasAdaptRate * (rawRate - estimatedBias);
        }
        return rawRate - estimatedBias;
    }
};
}
