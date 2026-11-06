#pragma once
#include <algorithm>
#include <cmath>
#include <cstdint>

namespace dualsense {
struct PerceptualLuminanceLut {
    static std::uint8_t linearToPerceptual(std::uint8_t linear) {
        float norm = static_cast<float>(linear) / 255.0f;
        float perceptual = (norm <= 0.08f) ? (norm / 9.033f) : std::pow((norm + 0.16f) / 1.16f, 3.0f);
        return static_cast<std::uint8_t>(std::clamp(perceptual * 255.0f, 0.0f, 255.0f));
    }
};
}
