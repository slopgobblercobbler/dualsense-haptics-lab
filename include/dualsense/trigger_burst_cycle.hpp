#pragma once
#include <cstdint>

namespace dualsense {
struct TriggerBurstCycle {
    static constexpr bool is_active_phase(std::uint32_t cycle_frame, std::uint32_t pulse_len, std::uint32_t period) noexcept {
        const std::uint32_t phase = cycle_frame % period;
        return phase < pulse_len;
    }
};
}
