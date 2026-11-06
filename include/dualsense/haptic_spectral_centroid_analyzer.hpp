#pragma once
#include <cmath>
#include <vector>

namespace dualsense {
struct SpectralCentroidAnalyzer {
    static float calculateCentroid(const std::vector<float>& magnitudes, float binHz = 10.0f) {
        float weightedSum = 0.0f;
        float totalMag = 0.0f;
        for (std::size_t i = 0; i < magnitudes.size(); ++i) {
            float freq = static_cast<float>(i) * binHz;
            weightedSum += freq * magnitudes[i];
            totalMag += magnitudes[i];
        }
        if (totalMag <= 0.0001f) return 0.0f;
        return weightedSum / totalMag;
    }
};
}
