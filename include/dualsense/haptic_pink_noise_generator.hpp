#pragma once
#include <cstdint>
#include <vector>

namespace dualsense {
struct PinkNoiseGenerator {
    static std::vector<float> generate(std::uint32_t sampleCount) {
        std::vector<float> samples(sampleCount, 0.0f);
        float b0 = 0.0f, b1 = 0.0f, b2 = 0.0f;
        for (std::uint32_t i = 0; i < sampleCount; ++i) {
            float white = (static_cast<float>(i % 100) / 50.0f) - 1.0f;
            b0 = 0.99886f * b0 + white * 0.0555179f;
            b1 = 0.99332f * b1 + white * 0.0750759f;
            b2 = 0.96900f * b2 + white * 0.1538520f;
            samples[i] = (b0 + b1 + b2 + white * 0.5362f) * 0.11f;
        }
        return samples;
    }
};
}
