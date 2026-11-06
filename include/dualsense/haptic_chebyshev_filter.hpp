#pragma once
#include <cstdint>
#include <cmath>

namespace dualsense {
struct ChebyshevLowPass {
    float state1{0.0f};
    float state2{0.0f};
    float process(float sample) noexcept {
        constexpr float a0 = 0.0976f;
        constexpr float a1 = 0.1952f;
        constexpr float a2 = 0.0976f;
        constexpr float b1 = -0.9428f;
        constexpr float b2 = 0.3333f;
        const float out = a0 * sample + state1;
        state1 = a1 * sample - b1 * out + state2;
        state2 = a2 * sample - b2 * out;
        return out;
    }
};
}
