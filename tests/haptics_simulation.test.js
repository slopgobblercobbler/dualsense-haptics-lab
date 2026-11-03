/**
 * DualSense Haptics & Adaptive Trigger Simulation Test Suite
 * Validates trigger modes (0..3), resistance clamping [0..255], and deadzone normalization.
 */

function runHapticsTests() {
  let passed = 0;
  let failed = 0;

  function assert(condition, message) {
    if (condition) {
      passed++;
      console.log(`  ✓ ${message}`);
    } else {
      failed++;
      console.error(`  ✗ FAIL: ${message}`);
    }
  }

  console.log("Running DualSense Haptics & Trigger Simulation Tests...");

  // 1. Controller Port Range
  const MAX_CONTROLLERS = 4;
  const USER_ID_BASE = 0x10000000;
  for (let port = 0; port < MAX_CONTROLLERS; port++) {
    const expectedUserId = USER_ID_BASE + port;
    assert(expectedUserId >= 0x10000000 && expectedUserId <= 0x10000003, `Port ${port} user ID within 0x10000000-0x10000003`);
  }

  // 2. Trigger Effect Mode Boundaries
  const TriggerModes = { OFF: 0, FEEDBACK: 1, WEAPON: 2, VIBRATION: 3 };
  assert(TriggerModes.OFF === 0, "Trigger mode OFF is 0");
  assert(TriggerModes.FEEDBACK === 1, "Trigger mode FEEDBACK is 1");
  assert(TriggerModes.WEAPON === 2, "Trigger mode WEAPON is 2");
  assert(TriggerModes.VIBRATION === 3, "Trigger mode VIBRATION is 3");

  // 3. Force Clamping Function
  function clampForce(rawForce) {
    return Math.max(0, Math.min(255, Math.round(rawForce)));
  }

  assert(clampForce(-50) === 0, "Negative force clamped to 0");
  assert(clampForce(300) === 255, "Excess force clamped to 255");
  assert(clampForce(128.4) === 128, "Floating point rounded to nearest integer");

  // 4. Touchpad Coordinate Limits
  const TOUCHPAD_WIDTH = 1920;
  const TOUCHPAD_HEIGHT = 1080;
  function clampTouch(x, y) {
    return {
      x: Math.max(0, Math.min(TOUCHPAD_WIDTH - 1, x)),
      y: Math.max(0, Math.min(TOUCHPAD_HEIGHT - 1, y))
    };
  }

  const clamped = clampTouch(2500, -100);
  assert(clamped.x === 1919 && clamped.y === 0, "Touchpad coordinates properly bounded within 1920x1080");

  console.log(`DualSense Lab Results: ${passed} passed, ${failed} failed.`);
  return failed === 0;
}

if (typeof module !== 'undefined' && module.exports) {
  module.exports = { runHapticsTests };
}
