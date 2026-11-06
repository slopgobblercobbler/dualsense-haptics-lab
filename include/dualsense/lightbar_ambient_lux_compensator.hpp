#pragma once
#include <algorithm>
#include <cstdint>

namespace dualsense {
struct LuxCompensator {
    static float calculateScaling(float lux, float minLux = 10.0f, float maxLux = 1000.0f) {
        if (lux <= minLux) return 0.25f;
        if (lux >= maxLux) return 1.0f;
        return 0.25f + 0.75f * ((lux - minLux) / (maxLux - minLux));
    }
};
}
