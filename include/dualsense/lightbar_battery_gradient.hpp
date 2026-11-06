#pragma once
#include <cstdint>

namespace dualsense {
struct LightbarBatteryGradient {
    struct Color { std::uint8_t r; std::uint8_t g; std::uint8_t b; };
    static constexpr Color get_status_color(std::uint8_t battery_percent) noexcept {
        if (battery_percent <= 15) return {255, 0, 0};
        if (battery_percent <= 50) return {255, 200, 0};
        return {0, 255, 0};
    }
};
}
