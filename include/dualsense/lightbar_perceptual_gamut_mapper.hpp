#pragma once
#include <algorithm>
#include <cstdint>

namespace dualsense {
struct GamutMapper {
    static void mapHuePreserving(std::uint8_t inR, std::uint8_t inG, std::uint8_t inB,
                                 std::uint8_t& outR, std::uint8_t& outG, std::uint8_t& outB, float maxLuma = 220.0f) {
        float luma = 0.2126f * inR + 0.7152f * inG + 0.0722f * inB;
        if (luma > maxLuma && luma > 0.0f) {
            float scale = maxLuma / luma;
            outR = static_cast<std::uint8_t>(inR * scale);
            outG = static_cast<std::uint8_t>(inG * scale);
            outB = static_cast<std::uint8_t>(inB * scale);
        } else {
            outR = inR; outG = inG; outB = inB;
        }
    }
};
}
