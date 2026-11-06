import json
import os
import unittest

class TestDualSensePhaseInversion(unittest.TestCase):
    def setUp(self):
        p = os.path.join(os.path.dirname(__file__), '..', 'src', 'dualsense_haptic_phase_inversion.json')
        with open(p, 'r') as f:
            self.data = json.load(f)

    def test_inversion(self):
        self.assertTrue(self.data['enable_inversion'])
        self.assertEqual(self.data['phase_offset_deg'], 180.0)

if __name__ == '__main__':
    unittest.main()
