#pragma once
#include <cmath>
#include <cstdint>

namespace dualsense {
struct TriggerFeedbackPulseTrain {
    static float computeBurst(float position, float pulseWidth, float pulseSpacing) {
        float cycle = pulseWidth + pulseSpacing;
        if (cycle <= 0.0001f) return 0.0f;
        float posInCycle = std::fmod(position, cycle);
        return (posInCycle < pulseWidth) ? 1.0f : 0.0f;
    }
};
}
