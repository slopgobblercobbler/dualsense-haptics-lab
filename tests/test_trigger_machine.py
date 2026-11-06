import json
import os
import unittest

class TestTriggerMachine(unittest.TestCase):
    def setUp(self):
        p = os.path.join(os.path.dirname(__file__), '..', 'src', 'adaptive_trigger_machine_effect.json')
        with open(p, 'r') as f:
            self.data = json.load(f)

    def test_machine_mode(self):
        self.assertEqual(self.data['TRIGGER_MODE_MACHINE'], 5)
        self.assertGreater(self.data['pulse_frequency_hz'], 0)

if __name__ == '__main__':
    unittest.main()
