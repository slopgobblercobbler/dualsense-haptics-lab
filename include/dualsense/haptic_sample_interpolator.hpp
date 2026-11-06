#pragma once
#include <cstdint>

namespace dualsense {
struct HapticSampleInterpolator {
    static constexpr float lerp(float a, float b, float t) noexcept {
        return a + t * (b - a);
    }
};
}
