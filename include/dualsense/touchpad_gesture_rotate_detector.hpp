#pragma once
#include <cmath>

namespace dualsense {
struct RotateGestureDetector {
    static float computeAngleRad(float x0, float y0, float x1, float y1) {
        return std::atan2(y1 - y0, x1 - x0);
    }
    static float computeDeltaAngle(float prevAngle, float currAngle) {
        float diff = currAngle - prevAngle;
        while (diff > 3.14159265f) diff -= 2.0f * 3.14159265f;
        while (diff < -3.14159265f) diff += 2.0f * 3.14159265f;
        return diff;
    }
};
}
