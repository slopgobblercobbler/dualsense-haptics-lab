import json
import os
import unittest

class TestPlayerLeds(unittest.TestCase):
    def setUp(self):
        p = os.path.join(os.path.dirname(__file__), '..', 'src', 'player_indicator_leds.json')
        with open(p, 'r') as f:
            self.data = json.load(f)

    def test_patterns(self):
        self.assertEqual(self.data['PLAYER_1'], 0x04)
        self.assertEqual(self.data['PLAYER_2'], 0x0A)
        self.assertEqual(self.data['PLAYER_3'], 0x15)
        self.assertEqual(self.data['PLAYER_4'], 0x1B)

if __name__ == '__main__':
    unittest.main()
