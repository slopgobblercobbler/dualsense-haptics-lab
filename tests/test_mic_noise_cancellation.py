import json
import os
import unittest

class TestMicNoiseCancellation(unittest.TestCase):
    def setUp(self):
        p = os.path.join(os.path.dirname(__file__), '..', 'src', 'dual_mic_noise_cancellation_dsp.json')
        with open(p, 'r') as f:
            self.data = json.load(f)

    def test_dsp(self):
        self.assertEqual(self.data['sampling_rate_hz'], 48000)
        self.assertLess(self.data['attenuation_depth_db'], 0)

if __name__ == '__main__':
    unittest.main()
