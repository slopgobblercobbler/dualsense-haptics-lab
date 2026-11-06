#pragma once
#include <cmath>

namespace dualsense {
struct TriggerFeedbackNotchFilter {
    static float filter(float input, float prevInput, float prevOutput, float notchFreq = 120.0f, float dt = 0.001f) {
        float w0 = 2.0f * 3.14159265f * notchFreq;
        float alpha = w0 * dt / 2.0f;
        float b0 = 1.0f / (1.0f + alpha);
        return b0 * (input - prevInput) + b0 * prevOutput;
    }
};
}
