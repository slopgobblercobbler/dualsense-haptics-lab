#pragma once
#include <cmath>
#include <numbers>

namespace dualsense {
struct HapticPhaseSync {
    static constexpr float compute_phase_offset(float freq_hz, float delay_sec) noexcept {
        return 2.0f * std::numbers::pi_v<float> * freq_hz * delay_sec;
    }
};
}
