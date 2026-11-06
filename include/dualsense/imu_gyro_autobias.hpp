#pragma once

namespace dualsense {
struct ImuGyroAutoBias {
    float bias_x{0.0f};
    float bias_y{0.0f};
    float bias_z{0.0f};
    void calibrate(float gx, float gy, float gz, float learning_rate) noexcept {
        bias_x += (gx - bias_x) * learning_rate;
        bias_y += (gy - bias_y) * learning_rate;
        bias_z += (gz - bias_z) * learning_rate;
    }
};
}
