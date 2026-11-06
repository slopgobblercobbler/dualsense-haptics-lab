#pragma once
#include <cmath>

namespace dualsense {
struct PinchSpreadGesture {
    static float distance(float x0, float y0, float x1, float y1) {
        float dx = x1 - x0;
        float dy = y1 - y0;
        return std::sqrt(dx * dx + dy * dy);
    }
    static float deltaScale(float prevDist, float currDist) {
        if (prevDist <= 0.0001f) return 1.0f;
        return currDist / prevDist;
    }
};
}
