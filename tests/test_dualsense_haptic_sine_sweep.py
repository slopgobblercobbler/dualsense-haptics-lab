import json
import os
import unittest

class TestDualSenseSweep(unittest.TestCase):
    def setUp(self):
        p = os.path.join(os.path.dirname(__file__), '..', 'src', 'dualsense_haptic_sine_sweep_generator.json')
        with open(p, 'r') as f:
            self.data = json.load(f)

    def test_sweep(self):
        self.assertEqual(self.data['start_frequency_hz'], 20.0)
        self.assertEqual(self.data['stop_frequency_hz'], 400.0)

if __name__ == '__main__':
    unittest.main()
