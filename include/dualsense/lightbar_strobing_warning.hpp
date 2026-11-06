#pragma once
#include <cmath>
#include <cstdint>

namespace dualsense {
struct StrobingWarningLightbar {
    static void computeFlash(float t, float frequencyHz, std::uint8_t& r, std::uint8_t& g, std::uint8_t& b) {
        bool on = (std::fmod(t * frequencyHz, 1.0f) < 0.5f);
        r = on ? 255 : 0;
        g = 0;
        b = 0;
    }
};
}
