#pragma once
#include <algorithm>
#include <cstdint>

namespace dualsense {
struct LightbarThermalThrottler {
    static float calculateThermalDerating(float junctionTempC, float maxTempC = 85.0f, float throttleTempC = 65.0f) {
        if (junctionTempC <= throttleTempC) return 1.0f;
        if (junctionTempC >= maxTempC) return 0.2f;
        return 1.0f - 0.8f * ((junctionTempC - throttleTempC) / (maxTempC - throttleTempC));
    }
};
}
