import json
import os
import unittest

class TestTouchpadMultiTouch(unittest.TestCase):
    def setUp(self):
        p = os.path.join(os.path.dirname(__file__), '..', 'src', 'touchpad_multitouch_limits.json')
        with open(p, 'r') as f:
            self.data = json.load(f)

    def test_limits(self):
        self.assertEqual(self.data['max_fingers'], 2)
        self.assertEqual(self.data['touch_inactive_flag'], "0x80")

if __name__ == '__main__':
    unittest.main()
