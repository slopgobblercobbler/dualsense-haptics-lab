import json
import os
import unittest

class TestTriggerGallop(unittest.TestCase):
    def setUp(self):
        p = os.path.join(os.path.dirname(__file__), '..', 'src', 'trigger_gallop_timings.json')
        with open(p, 'r') as f:
            self.data = json.load(f)

    def test_intervals(self):
        self.assertLess(self.data['gallop_min_interval_ms'], self.data['gallop_max_interval_ms'])
        self.assertEqual(self.data['first_pulse_start_zone'], 2)

if __name__ == '__main__':
    unittest.main()
