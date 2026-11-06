import json
import os
import unittest

class TestTriggerBow(unittest.TestCase):
    def setUp(self):
        p = os.path.join(os.path.dirname(__file__), '..', 'src', 'adaptive_trigger_bow_effect.json')
        with open(p, 'r') as f:
            self.data = json.load(f)

    def test_bow_mode(self):
        self.assertEqual(self.data['TRIGGER_MODE_BOW'], 4)
        self.assertLess(self.data['holding_force_level'], self.data['snap_force_level'])

if __name__ == '__main__':
    unittest.main()
