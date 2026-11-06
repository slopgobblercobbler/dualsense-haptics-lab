#pragma once
#include <algorithm>
#include <cmath>
#include <cstdint>

namespace dualsense {
struct AmbientColorTemp {
    static void kelvinToRgb(float kelvin, std::uint8_t& r, std::uint8_t& g, std::uint8_t& b) {
        float temp = std::clamp(kelvin, 1000.0f, 40000.0f) / 100.0f;
        float rf = (temp <= 66.0f) ? 255.0f : 329.698727446f * std::pow(temp - 60.0f, -0.1332047592f);
        float gf = (temp <= 66.0f) ? 99.4708025861f * std::log(temp) - 161.1195681661f : 288.1221695283f * std::pow(temp - 60.0f, -0.0755148492f);
        float bf = (temp >= 66.0f) ? 255.0f : (temp <= 19.0f) ? 0.0f : 138.5177312231f * std::log(temp - 10.0f) - 305.0447927307f;
        r = static_cast<std::uint8_t>(std::clamp(rf, 0.0f, 255.0f));
        g = static_cast<std::uint8_t>(std::clamp(gf, 0.0f, 255.0f));
        b = static_cast<std::uint8_t>(std::clamp(bf, 0.0f, 255.0f));
    }
};
}
