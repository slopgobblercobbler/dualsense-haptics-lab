#pragma once
#include <cstdint>
#include <algorithm>

namespace dualsense {
struct TriggerParabolicCurve {
    static constexpr std::uint8_t compute(std::uint8_t pos, float curvature) noexcept {
        const float norm = static_cast<float>(pos) / 255.0f;
        const float force = curvature * norm * norm * 255.0f;
        return static_cast<std::uint8_t>(std::clamp(force, 0.0f, 255.0f));
    }
};
}
