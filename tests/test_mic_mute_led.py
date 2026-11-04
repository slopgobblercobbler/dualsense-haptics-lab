import json
import os
import unittest

class TestMicMuteLed(unittest.TestCase):
    def setUp(self):
        p = os.path.join(os.path.dirname(__file__), '..', 'src', 'mic_mute_led.json')
        with open(p, 'r') as f:
            self.data = json.load(f)

    def test_mute_states(self):
        self.assertEqual(self.data['MUTE_OFF'], 0)
        self.assertEqual(self.data['MUTE_SOLID'], 1)
        self.assertEqual(self.data['MUTE_PULSE'], 2)

if __name__ == '__main__':
    unittest.main()
