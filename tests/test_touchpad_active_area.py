import json
import os
import unittest

class TestTouchpadActiveArea(unittest.TestCase):
    def setUp(self):
        p = os.path.join(os.path.dirname(__file__), '..', 'src', 'touchpad_active_area.json')
        with open(p, 'r') as f:
            self.data = json.load(f)

    def test_dimensions(self):
        self.assertEqual(self.data['active_max_x'], 1920)
        self.assertEqual(self.data['active_max_y'], 1080)

if __name__ == '__main__':
    unittest.main()
