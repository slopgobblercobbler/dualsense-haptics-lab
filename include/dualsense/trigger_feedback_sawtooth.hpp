#pragma once
#include <cmath>

namespace dualsense {
struct TriggerFeedbackSawtooth {
    static float computeResistance(float position, float period) {
        if (period <= 0.0001f) return 0.0f;
        float normalized = std::fmod(position, period) / period;
        return normalized;
    }
};
}
