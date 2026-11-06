#pragma once
#include <cmath>
#include <cstdint>

namespace dualsense {
struct LightbarBreathingCycle {
    static void computeRgb(float t, float period, std::uint8_t baseR, std::uint8_t baseG, std::uint8_t baseB,
                           std::uint8_t& outR, std::uint8_t& outG, std::uint8_t& outB) {
        float factor = 0.5f * (1.0f + std::sin(6.2831853f * t / period));
        outR = static_cast<std::uint8_t>(baseR * factor);
        outG = static_cast<std::uint8_t>(baseG * factor);
        outB = static_cast<std::uint8_t>(baseB * factor);
    }
};
}
