import json
import os
import unittest

class TestDualSenseEqualizer(unittest.TestCase):
    def setUp(self):
        p = os.path.join(os.path.dirname(__file__), '..', 'src', 'dualsense_haptic_equalizer_bands.json')
        with open(p, 'r') as f:
            self.data = json.load(f)

    def test_eq_bands(self):
        self.assertEqual(self.data['low_shelf_hz'], 60.0)
        self.assertEqual(self.data['peaking_hz'], 160.0)

if __name__ == '__main__':
    unittest.main()
