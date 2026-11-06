#pragma once
#include <algorithm>
#include <cmath>
#include <vector>

namespace dualsense {
struct HapticCompressor {
    static void compress(std::vector<float>& signal, float threshold = 0.7f, float ratio = 4.0f) {
        for (auto& s : signal) {
            float absVal = std::abs(s);
            if (absVal > threshold) {
                float excess = absVal - threshold;
                float compressed = threshold + (excess / ratio);
                s = (s >= 0.0f) ? compressed : -compressed;
            }
        }
    }
};
}
