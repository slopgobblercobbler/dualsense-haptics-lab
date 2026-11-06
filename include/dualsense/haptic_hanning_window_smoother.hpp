#pragma once
#include <cmath>
#include <vector>

namespace dualsense {
struct HanningWindowSmoother {
    static void applyWindow(std::vector<float>& signal) {
        std::size_t n = signal.size();
        if (n <= 1) return;
        for (std::size_t i = 0; i < n; ++i) {
            float multiplier = 0.5f * (1.0f - std::cos(2.0f * 3.14159265f * static_cast<float>(i) / static_cast<float>(n - 1)));
            signal[i] *= multiplier;
        }
    }
};
}
