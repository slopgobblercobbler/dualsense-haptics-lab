#pragma once
#include <cmath>

namespace dualsense {
struct TouchpadPalmRejection {
    static bool isPalmTouch(float x, float y, float contactMajor, float edgeMargin = 80.0f, float palmSizeThreshold = 250.0f) {
        if (contactMajor >= palmSizeThreshold) return true;
        if (x < edgeMargin || x > (1920.0f - edgeMargin)) return true;
        if (y < edgeMargin || y > (1080.0f - edgeMargin)) return true;
        return false;
    }
};
}
