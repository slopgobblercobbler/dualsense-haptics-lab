import json
import os
import unittest

class TestHardClipper(unittest.TestCase):
    def setUp(self):
        p = os.path.join(os.path.dirname(__file__), '..', 'src', 'audio_dsp_hard_clipper_transfer.json')
        with open(p, 'r') as f:
            self.data = json.load(f)

    def test_clipper(self):
        self.assertEqual(self.data['clipping_threshold'], 0.95)
        self.assertEqual(self.data['output_limit'], 1.0)

if __name__ == '__main__':
    unittest.main()
