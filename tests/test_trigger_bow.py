import json
import os
import unittest

class TestTriggerBow(unittest.TestCase):
    def setUp(self):
        p = os.path.join(os.path.dirname(__file__), '..', 'src', 'trigger_bow_effect.json')
        with open(p, 'r') as f:
            self.data = json.load(f)

    def test_bow_bounds(self):
        self.assertEqual(self.data['min_start_pos'], 0)
        self.assertEqual(self.data['max_end_pos'], 9)
        self.assertEqual(self.data['max_force'], 8)

if __name__ == '__main__':
    unittest.main()
