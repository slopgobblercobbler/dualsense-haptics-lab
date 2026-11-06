#pragma once
#include <cstdint>
#include <cmath>

namespace dualsense {
struct TriggerTriangleWave {
    static constexpr std::uint8_t generate(std::uint32_t time_frame, std::uint32_t period) noexcept {
        if (period == 0) return 0;
        const std::uint32_t half = period / 2;
        const std::uint32_t phase = time_frame % period;
        if (phase < half) {
            return static_cast<std::uint8_t>(phase * 255u / half);
        } else {
            return static_cast<std::uint8_t>((period - phase) * 255u / half);
        }
    }
};
}
