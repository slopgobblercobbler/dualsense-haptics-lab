#pragma once
#include <cmath>

namespace dualsense {
struct TapVelocityEstimator {
    static float estimateSpeed(float x0, float y0, float x1, float y1, float dt) {
        if (dt <= 0.0001f) return 0.0f;
        float dist = std::sqrt((x1 - x0) * (x1 - x0) + (y1 - y0) * (y1 - y0));
        return dist / dt;
    }
};
}
