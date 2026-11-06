#pragma once
#include <cmath>

namespace dualsense {
struct TriggerFeedbackStaircase {
    static float computeDetent(float position, int numSteps = 4) {
        if (numSteps <= 0) return 0.0f;
        float stepSize = 1.0f / static_cast<float>(numSteps);
        float currentStep = std::floor(position / stepSize);
        return currentStep * stepSize;
    }
};
}
