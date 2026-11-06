#pragma once
#include <cstdint>
#include <cmath>
#include <numbers>

namespace dualsense {
struct LightbarBreathingFade {
    static constexpr std::uint8_t calculate_intensity(float time_sec, float period_sec) noexcept {
        const float normalized = (std::sin(2.0f * std::numbers::pi_v<float> * time_sec / period_sec) + 1.0f) * 0.5f;
        return static_cast<std::uint8_t>(normalized * 255.0f);
    }
};
}
