#pragma once

namespace dualsense {
struct ImuDeadReckoning {
    float pos_x{0.0f}, pos_y{0.0f}, pos_z{0.0f};
    float vel_x{0.0f}, vel_y{0.0f}, vel_z{0.0f};
    void integrate(float ax, float ay, float az, float dt) noexcept {
        vel_x += ax * dt; vel_y += ay * dt; vel_z += az * dt;
        pos_x += vel_x * dt; pos_y += vel_y * dt; pos_z += vel_z * dt;
    }
};
}
