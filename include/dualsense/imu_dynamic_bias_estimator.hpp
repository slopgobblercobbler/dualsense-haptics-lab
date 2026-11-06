#pragma once
#include <cmath>

namespace dualsense {
struct DynamicBiasEstimator {
    float biasX{0.0f}, biasY{0.0f}, biasZ{0.0f};
    void update(float gx, float gy, float gz, bool isStatic, float rate = 0.005f) {
        if (isStatic) {
            biasX += rate * (gx - biasX);
            biasY += rate * (gy - biasY);
            biasZ += rate * (gz - biasZ);
        }
    }
};
}
