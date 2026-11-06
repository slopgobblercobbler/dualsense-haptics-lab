#pragma once
#include <cstdint>
#include <cstddef>
#include <vector>

namespace dualsense {
struct HapticChannelDelay {
    std::vector<float> buffer;
    std::size_t index{0};
    explicit HapticChannelDelay(std::size_t delay_samples) : buffer(delay_samples, 0.0f) {}
    float process(float sample) noexcept {
        if (buffer.empty()) return sample;
        const float out = buffer[index];
        buffer[index] = sample;
        index = (index + 1) % buffer.size();
        return out;
    }
};
}
