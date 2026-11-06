#pragma once

namespace dualsense {
struct HapticSubHarmonic {
    bool toggle{false};
    float process(float sample) noexcept {
        toggle = !toggle;
        return toggle ? sample : -sample;
    }
};
}
