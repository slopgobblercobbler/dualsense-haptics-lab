import json
import os
import unittest

class TestPulseGenerator(unittest.TestCase):
    def setUp(self):
        p = os.path.join(os.path.dirname(__file__), '..', 'src', 'rumble_pulse_generator.json')
        with open(p, 'r') as f:
            self.data = json.load(f)

    def test_limits(self):
        self.assertEqual(self.data['min_frequency_hz'], 10)
        self.assertEqual(self.data['max_frequency_hz'], 300)

if __name__ == '__main__':
    unittest.main()
