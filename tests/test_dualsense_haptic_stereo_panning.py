import json
import os
import unittest

class TestDualSenseStereoPan(unittest.TestCase):
    def setUp(self):
        p = os.path.join(os.path.dirname(__file__), '..', 'src', 'dualsense_haptic_stereo_panning.json')
        with open(p, 'r') as f:
            self.data = json.load(f)

    def test_panning(self):
        self.assertEqual(self.data['panning_law'], 'EQUAL_POWER_3DB')
        self.assertEqual(self.data['crossfeed_ratio'], 0.15)

if __name__ == '__main__':
    unittest.main()
