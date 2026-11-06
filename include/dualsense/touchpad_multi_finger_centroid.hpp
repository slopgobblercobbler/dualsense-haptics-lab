#pragma once
#include <cstdint>
#include <vector>

namespace dualsense {
struct TouchPoint { float x; float y; };
struct CentroidTracker {
    static bool calculate(const std::vector<TouchPoint>& touches, float& cx, float& cy) {
        if (touches.empty()) return false;
        float sumX = 0.0f, sumY = 0.0f;
        for (const auto& t : touches) { sumX += t.x; sumY += t.y; }
        cx = sumX / static_cast<float>(touches.size());
        cy = sumY / static_cast<float>(touches.size());
        return true;
    }
};
}
