#pragma once
#include <cstdint>
#include <algorithm>

namespace dualsense {
struct TriggerFreqModulator {
    static constexpr std::uint8_t modulate(std::uint8_t base_freq, float speed_factor) noexcept {
        const float scaled = static_cast<float>(base_freq) * speed_factor;
        return static_cast<std::uint8_t>(std::clamp(scaled, 1.0f, 255.0f));
    }
};
}
