import json
import os
import unittest

class TestPinkNoiseGenerator(unittest.TestCase):
    def setUp(self):
        p = os.path.join(os.path.dirname(__file__), '..', 'src', 'audio_dsp_pink_noise_generator.json')
        with open(p, 'r') as f:
            self.data = json.load(f)

    def test_pink_noise(self):
        self.assertEqual(self.data['num_stages'], 5)
        self.assertEqual(self.data['roll_off_db_per_octave'], -3.0)

if __name__ == '__main__':
    unittest.main()
