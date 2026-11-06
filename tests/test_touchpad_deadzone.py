import json
import os
import unittest

class TestTouchpadDeadzone(unittest.TestCase):
    def setUp(self):
        p = os.path.join(os.path.dirname(__file__), '..', 'src', 'touchpad_active_deadzone.json')
        with open(p, 'r') as f:
            self.data = json.load(f)

    def test_margins(self):
        self.assertEqual(self.data['x_border_margin_px'], 16)
        self.assertEqual(self.data['hysteresis_filter_px'], 3)

if __name__ == '__main__':
    unittest.main()
