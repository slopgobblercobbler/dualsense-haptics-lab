#pragma once
#include <cstdint>
#include <array>

namespace dualsense {
struct TriggerTorqueLut {
    std::array<std::uint8_t, 10> torque_profile{};
    constexpr std::uint8_t sample(std::uint8_t zone_idx) const noexcept {
        return (zone_idx < torque_profile.size()) ? torque_profile[zone_idx] : 0;
    }
};
}
