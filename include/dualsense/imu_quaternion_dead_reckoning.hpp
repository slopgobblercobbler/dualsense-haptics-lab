#pragma once
#include <cmath>

namespace dualsense {
struct QuaternionDeadReckoning {
    float w{1.0f}, x{0.0f}, y{0.0f}, z{0.0f};
    void integrateRate(float gx, float gy, float gz, float dt) {
        float halfDt = 0.5f * dt;
        float nw = w + (-x * gx - y * gy - z * gz) * halfDt;
        float nx = x + ( w * gx + y * gz - z * gy) * halfDt;
        float ny = y + ( w * gy - x * gz + z * gx) * halfDt;
        float nz = z + ( w * gz + x * gy - y * gx) * halfDt;
        float norm = std::sqrt(nw*nw + nx*nx + ny*ny + nz*nz);
        if (norm > 0.0001f) { w = nw/norm; x = nx/norm; y = ny/norm; z = nz/norm; }
    }
};
}
