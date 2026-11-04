import json
import os
import unittest

class TestTriggerModes(unittest.TestCase):
    def setUp(self):
        p = os.path.join(os.path.dirname(__file__), '..', 'src', 'trigger_effect_modes.json')
        with open(p, 'r') as f:
            self.data = json.load(f)

    def test_trigger_modes(self):
        self.assertEqual(self.data['TRIGGER_TYPE_OFF'], 0)
        self.assertEqual(self.data['TRIGGER_TYPE_FEEDBACK'], 1)
        self.assertEqual(self.data['TRIGGER_TYPE_WEAPON'], 2)
        self.assertEqual(self.data['TRIGGER_TYPE_VIBRATION'], 3)

if __name__ == '__main__':
    unittest.main()
