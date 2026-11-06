import json
import os
import unittest

class TestTapDetection(unittest.TestCase):
    def setUp(self):
        p = os.path.join(os.path.dirname(__file__), '..', 'src', 'touchpad_tap_detection_window.json')
        with open(p, 'r') as f:
            self.data = json.load(f)

    def test_tap(self):
        self.assertEqual(self.data['max_tap_duration_ms'], 180)
        self.assertEqual(self.data['max_finger_movement_pixels'], 15)

if __name__ == '__main__':
    unittest.main()
