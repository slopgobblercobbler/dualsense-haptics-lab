#pragma once
#include <cmath>

namespace dualsense {
struct FlickDetector {
    static bool isFlick(float vx, float vy, float minVelocity = 800.0f) {
        float speedSq = vx * vx + vy * vy;
        return speedSq >= (minVelocity * minVelocity);
    }
};
}
