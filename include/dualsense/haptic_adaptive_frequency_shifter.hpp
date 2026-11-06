#pragma once
#include <cmath>
#include <vector>

namespace dualsense {
struct FrequencyShifter {
    static std::vector<float> shift(const std::vector<float>& signal, float shiftHz, float sampleRate = 1000.0f) {
        std::vector<float> shifted(signal.size(), 0.0f);
        float phaseInc = 2.0f * 3.14159265f * shiftHz / sampleRate;
        float phase = 0.0f;
        for (std::size_t i = 0; i < signal.size(); ++i) {
            shifted[i] = signal[i] * std::cos(phase);
            phase = std::fmod(phase + phaseInc, 2.0f * 3.14159265f);
        }
        return shifted;
    }
};
}
