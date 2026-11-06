#pragma once

namespace dualsense {
struct HapticBiquadNotch {
    float x1{0.0f}, x2{0.0f};
    float y1{0.0f}, y2{0.0f};
    float process(float in, float b0, float b1, float b2, float a1, float a2) noexcept {
        const float out = b0 * in + b1 * x1 + b2 * x2 - a1 * y1 - a2 * y2;
        x2 = x1; x1 = in;
        y2 = y1; y1 = out;
        return out;
    }
};
}
