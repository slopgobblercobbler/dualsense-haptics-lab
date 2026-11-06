#pragma once
#include <algorithm>
#include <cmath>
#include <cstdint>

namespace dualsense {
struct RainbowColorCycle {
    static void computeHsvToRgb(float hueDeg, std::uint8_t& r, std::uint8_t& g, std::uint8_t& b) {
        float h = std::fmod(hueDeg, 360.0f) / 60.0f;
        float x = 1.0f - std::abs(std::fmod(h, 2.0f) - 1.0f);
        float rf = 0.0f, gf = 0.0f, bf = 0.0f;
        if (h < 1.0f) { rf = 1.0f; gf = x; }
        else if (h < 2.0f) { rf = x; gf = 1.0f; }
        else if (h < 3.0f) { gf = 1.0f; bf = x; }
        else if (h < 4.0f) { gf = x; bf = 1.0f; }
        else if (h < 5.0f) { rf = x; bf = 1.0f; }
        else { rf = 1.0f; bf = x; }
        r = static_cast<std::uint8_t>(rf * 255.0f);
        g = static_cast<std::uint8_t>(gf * 255.0f);
        b = static_cast<std::uint8_t>(bf * 255.0f);
    }
};
}
