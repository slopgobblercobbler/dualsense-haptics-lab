import json
import os
import unittest

class TestTriggerCalibration(unittest.TestCase):
    def setUp(self):
        p = os.path.join(os.path.dirname(__file__), '..', 'src', 'adaptive_trigger_calibration_limits.json')
        with open(p, 'r') as f:
            self.data = json.load(f)

    def test_calibration(self):
        self.assertEqual(self.data['max_position'], 255)
        self.assertLess(self.data['mechanical_hard_stop'], 255)

if __name__ == '__main__':
    unittest.main()
