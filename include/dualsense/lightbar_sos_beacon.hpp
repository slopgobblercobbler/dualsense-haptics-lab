#pragma once
#include <cstdint>
#include <array>

namespace dualsense {
struct LightbarSosBeacon {
    static constexpr std::array<bool, 9> sos_pattern{
        true, true, true,       // S (...)
        false, false, false,   // gap
        true, true, true       // S (...)
    };
    static constexpr bool is_light_on(std::size_t step) noexcept {
        return (step < sos_pattern.size()) ? sos_pattern[step] : false;
    }
};
}
