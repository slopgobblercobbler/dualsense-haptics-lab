import json
import os
import unittest

class TestDualSenseUpsampler(unittest.TestCase):
    def setUp(self):
        p = os.path.join(os.path.dirname(__file__), '..', 'src', 'dualsense_haptic_pcm_upsampler.json')
        with open(p, 'r') as f:
            self.data = json.load(f)

    def test_upsampler(self):
        self.assertEqual(self.data['input_rate_hz'], 48000)
        self.assertEqual(self.data['output_rate_hz'], 96000)

if __name__ == '__main__':
    unittest.main()
