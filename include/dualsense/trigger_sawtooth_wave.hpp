#pragma once
#include <cstdint>

namespace dualsense {
struct TriggerSawtoothWave {
    static constexpr std::uint8_t generate(std::uint32_t time_frame, std::uint32_t period) noexcept {
        if (period == 0) return 0;
        return static_cast<std::uint8_t>((time_frame % period) * 255u / period);
    }
};
}
