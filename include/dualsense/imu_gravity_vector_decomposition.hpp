#pragma once
#include <cmath>

namespace dualsense {
struct GravityDecomposer {
    static void extractLinearAccel(float ax, float ay, float az, float gx, float gy, float gz,
                                  float& linX, float& linY, float& linZ) {
        linX = ax - gx;
        linY = ay - gy;
        linZ = az - gz;
    }
};
}
