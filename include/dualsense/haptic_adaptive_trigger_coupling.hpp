#pragma once
#include <algorithm>

namespace dualsense {
struct TriggerHapticCoupler {
    static float decouple(float hapticSignal, float triggerMotorFeedback, float couplingCoeff = 0.15f) {
        float compensation = triggerMotorFeedback * couplingCoeff;
        return std::clamp(hapticSignal - compensation, -1.0f, 1.0f);
    }
};
}
