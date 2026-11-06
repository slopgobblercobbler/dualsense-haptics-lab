#pragma once
#include <cmath>

namespace dualsense {
struct TouchpadTapSlide {
    static constexpr float tap_window_sec = 0.2f;
    static constexpr float slide_min_dist = 40.0f;
    static bool is_tap_slide(float hold_time_sec, float move_dist) noexcept {
        return (hold_time_sec <= tap_window_sec) && (move_dist >= slide_min_dist);
    }
};
}
