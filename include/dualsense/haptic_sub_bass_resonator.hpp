#pragma once
#include <cmath>
#include <vector>

namespace dualsense {
struct SubBassResonator {
    static std::vector<float> process(const std::vector<float>& input, float cutoffHz = 60.0f, float sampleRate = 1000.0f) {
        std::vector<float> output(input.size(), 0.0f);
        float rc = 1.0f / (2.0f * 3.14159265f * cutoffHz);
        float dt = 1.0f / sampleRate;
        float alpha = dt / (rc + dt);
        float prev = 0.0f;
        for (std::size_t i = 0; i < input.size(); ++i) {
            prev = prev + alpha * (input[i] - prev);
            output[i] = prev;
        }
        return output;
    }
};
}
