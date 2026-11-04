import json
import os
import unittest

class TestTriggerStops(unittest.TestCase):
    def setUp(self):
        p = os.path.join(os.path.dirname(__file__), '..', 'src', 'trigger_feedback_stops.json')
        with open(p, 'r') as f:
            self.data = json.load(f)

    def test_bounds(self):
        self.assertEqual(self.data['min_position'], 0)
        self.assertEqual(self.data['max_position'], 9)
        self.assertEqual(self.data['max_force'], 8)

if __name__ == '__main__':
    unittest.main()
