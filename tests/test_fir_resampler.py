import json
import os
import unittest

class TestFirResampler(unittest.TestCase):
    def setUp(self):
        p = os.path.join(os.path.dirname(__file__), '..', 'src', 'audio_dsp_fir_resampler_polyphase.json')
        with open(p, 'r') as f:
            self.data = json.load(f)

    def test_fir(self):
        self.assertEqual(self.data['num_taps'], 32)
        self.assertEqual(self.data['decimation_factor'], 192)

if __name__ == '__main__':
    unittest.main()
