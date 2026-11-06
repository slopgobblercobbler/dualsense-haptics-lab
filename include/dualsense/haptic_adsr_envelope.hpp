#pragma once
#include <algorithm>

namespace dualsense {
struct HapticAdsrEnvelope {
    float attack_time{0.01f};
    float decay_time{0.05f};
    float sustain_level{0.7f};
    float release_time{0.05f};
    float evaluate(float t, float gate_off_time) const noexcept {
        if (t < attack_time) return t / attack_time;
        if (t < attack_time + decay_time) {
            const float dt = t - attack_time;
            return 1.0f - (1.0f - sustain_level) * (dt / decay_time);
        }
        if (t < gate_off_time) return sustain_level;
        const float rt = t - gate_off_time;
        if (rt < release_time) return sustain_level * (1.0f - rt / release_time);
        return 0.0f;
    }
};
}
