#pragma once
#include <cmath>

namespace dualsense {
enum class SwipeDir { None, Left, Right, Up, Down };

struct TouchpadTriSwipe {
    static SwipeDir classify(float dx, float dy, float min_dist) noexcept {
        if (std::hypot(dx, dy) < min_dist) return SwipeDir::None;
        if (std::abs(dx) > std::abs(dy)) {
            return (dx > 0) ? SwipeDir::Right : SwipeDir::Left;
        } else {
            return (dy > 0) ? SwipeDir::Down : SwipeDir::Up;
        }
    }
};
}
