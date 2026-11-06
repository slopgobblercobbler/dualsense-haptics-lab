#pragma once
#include <cmath>

namespace dualsense {
struct ImuSlerp {
    struct Quat { float w, x, y, z; };
    static Quat interpolate(const Quat& q1, const Quat& q2, float t) noexcept {
        const float dot = q1.w * q2.w + q1.x * q2.x + q1.y * q2.y + q1.z * q2.z;
        if (dot > 0.9995f) {
            return {q1.w + t * (q2.w - q1.w), q1.x + t * (q2.x - q1.x),
                    q1.y + t * (q2.y - q1.y), q1.z + t * (q2.z - q1.z)};
        }
        const float theta = std::acos(dot);
        const float sin_theta = std::sin(theta);
        const float s1 = std::sin((1.0f - t) * theta) / sin_theta;
        const float s2 = std::sin(t * theta) / sin_theta;
        return {s1 * q1.w + s2 * q2.w, s1 * q1.x + s2 * q2.x,
                s1 * q1.y + s2 * q2.y, s1 * q1.z + s2 * q2.z};
    }
};
}
