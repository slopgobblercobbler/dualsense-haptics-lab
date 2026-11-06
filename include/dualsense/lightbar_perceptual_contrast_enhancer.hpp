#pragma once
#include <algorithm>
#include <cmath>
#include <cstdint>

namespace dualsense {
struct ContrastEnhancer {
    static std::uint8_t enhance(std::uint8_t val, float factor = 1.25f) {
        float norm = static_cast<float>(val) / 255.0f;
        float centered = (norm - 0.5f) * factor + 0.5f;
        return static_cast<std::uint8_t>(std::clamp(centered * 255.0f, 0.0f, 255.0f));
    }
};
}
