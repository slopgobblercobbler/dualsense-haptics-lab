#pragma once
#include <algorithm>

namespace dualsense {
struct CubicSplineTrigger {
    static float evaluateSpline(float p0, float p1, float m0, float m1, float t) {
        float ct = std::clamp(t, 0.0f, 1.0f);
        float t2 = ct * ct;
        float t3 = t2 * ct;
        float h00 = 2.0f * t3 - 3.0f * t2 + 1.0f;
        float h10 = t3 - 2.0f * t2 + ct;
        float h01 = -2.0f * t3 + 3.0f * t2;
        float h11 = t3 - t2;
        return h00 * p0 + h10 * m0 + h01 * p1 + h11 * m1;
    }
};
}
