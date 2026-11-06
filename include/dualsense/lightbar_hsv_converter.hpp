#pragma once
#include <cstdint>
#include <algorithm>
#include <cmath>

namespace dualsense {
struct LightbarHsvConverter {
    struct Rgb { std::uint8_t r; std::uint8_t g; std::uint8_t b; };
    static constexpr Rgb hsv_to_rgb(float h, float s, float v) noexcept {
        const float c = v * s;
        const float x = c * (1.0f - std::abs(std::fmod(h / 60.0f, 2.0f) - 1.0f));
        const float m = v - c;
        float r1 = 0, g1 = 0, b1 = 0;
        if (h < 60) { r1 = c; g1 = x; }
        else if (h < 120) { r1 = x; g1 = c; }
        else if (h < 180) { g1 = c; b1 = x; }
        else if (h < 240) { g1 = x; b1 = c; }
        else if (h < 300) { r1 = x; b1 = c; }
        else { r1 = c; b1 = x; }
        return {static_cast<std::uint8_t>((r1 + m) * 255.0f),
                static_cast<std::uint8_t>((g1 + m) * 255.0f),
                static_cast<std::uint8_t>((b1 + m) * 255.0f)};
    }
};
}
