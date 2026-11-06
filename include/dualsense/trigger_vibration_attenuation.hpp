#pragma once
#include <algorithm>
#include <cstdint>

namespace dualsense {
struct TriggerVibrationAttenuation {
    static float calculate(float baseForce, float dampingFactor, float velocity) {
        float damped = baseForce - (dampingFactor * velocity);
        return std::clamp(damped, 0.0f, 1.0f);
    }
};
}
