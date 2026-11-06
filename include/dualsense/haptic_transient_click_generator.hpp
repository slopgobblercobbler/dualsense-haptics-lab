#pragma once
#include <cmath>
#include <cstdint>
#include <vector>

namespace dualsense {
struct TransientClickGenerator {
    static std::vector<float> generateClick(std::uint32_t sampleCount, float frequency = 180.0f) {
        std::vector<float> samples(sampleCount, 0.0f);
        for (std::uint32_t i = 0; i < sampleCount; ++i) {
            float t = static_cast<float>(i) / 1000.0f;
            float decay = std::exp(-20.0f * t);
            samples[i] = std::sin(2.0f * 3.14159265f * frequency * t) * decay;
        }
        return samples;
    }
};
}
