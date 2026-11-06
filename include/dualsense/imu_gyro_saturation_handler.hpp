#pragma once
#include <algorithm>

namespace dualsense {
struct GyroSaturationHandler {
    static float clampRate(float rawRate, float maxRangeRadPerSec = 34.9f) {
        return std::clamp(rawRate, -maxRangeRadPerSec, maxRangeRadPerSec);
    }
};
}
