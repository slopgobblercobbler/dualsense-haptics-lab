import json
import os
import unittest

class TestDualSenseResonance(unittest.TestCase):
    def setUp(self):
        p = os.path.join(os.path.dirname(__file__), '..', 'src', 'dualsense_haptic_resonance_filter.json')
        with open(p, 'r') as f:
            self.data = json.load(f)

    def test_filter_params(self):
        self.assertEqual(self.data['resonant_frequency_hz'], 160.0)
        self.assertEqual(self.data['q_factor'], 4.5)

if __name__ == '__main__':
    unittest.main()
