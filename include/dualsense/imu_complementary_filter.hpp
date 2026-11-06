#pragma once
#include <cmath>

namespace dualsense {
struct ImuComplementaryFilter {
    float pitch{0.0f};
    float roll{0.0f};
    void update(float gyro_pitch_rate, float gyro_roll_rate, float accel_pitch, float accel_roll, float dt) noexcept {
        constexpr float alpha = 0.98f;
        pitch = alpha * (pitch + gyro_pitch_rate * dt) + (1.0f - alpha) * accel_pitch;
        roll = alpha * (roll + gyro_roll_rate * dt) + (1.0f - alpha) * accel_roll;
    }
};
}
