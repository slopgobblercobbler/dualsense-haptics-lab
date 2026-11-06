#pragma once
#include <cstdint>
#include <algorithm>

namespace dualsense {
struct TriggerSlopeFeedback {
    static constexpr std::uint8_t calculate_resistance(std::uint8_t pos, std::uint8_t start_pos, std::uint8_t slope_rate) noexcept {
        if (pos < start_pos) return 0;
        const std::uint32_t force = static_cast<std::uint32_t>(pos - start_pos) * slope_rate;
        return static_cast<std::uint8_t>(std::min(force, 255u));
    }
};
}
