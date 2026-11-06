#pragma once
#include <cmath>

namespace dualsense {
struct ImuComplementaryFilter {
    static float updatePitch(float prevPitch, float gyroPitchRate, float accelPitch, float dt, float alpha = 0.98f) {
        float integrated = prevPitch + gyroPitchRate * dt;
        return alpha * integrated + (1.0f - alpha) * accelPitch;
    }
};
}
