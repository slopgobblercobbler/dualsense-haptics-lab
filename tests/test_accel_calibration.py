import json
import os
import unittest

class TestAccelCalibration(unittest.TestCase):
    def setUp(self):
        p = os.path.join(os.path.dirname(__file__), '..', 'src', 'imu_accel_calibration_offsets.json')
        with open(p, 'r') as f:
            self.data = json.load(f)

    def test_accel(self):
        self.assertEqual(self.data['sensitivity_scale_lsb_per_g'], 8192)

if __name__ == '__main__':
    unittest.main()
