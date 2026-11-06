#pragma once

namespace dualsense {
struct ImuGravityRemoval {
    static void subtract_gravity(float ax, float ay, float az,
                                 float gx, float gy, float gz,
                                 float& out_lx, float& out_ly, float& out_lz) noexcept {
        out_lx = ax - gx;
        out_ly = ay - gy;
        out_lz = az - gz;
    }
};
}
