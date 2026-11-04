import json
import os
import unittest

class TestMotionQuaternions(unittest.TestCase):
    def setUp(self):
        p = os.path.join(os.path.dirname(__file__), '..', 'src', 'motion_quaternion_math.json')
        with open(p, 'r') as f:
            self.data = json.load(f)

    def test_components(self):
        self.assertEqual(len(self.data['quaternion_components']), 4)
        self.assertIn('w', self.data['quaternion_components'])

if __name__ == '__main__':
    unittest.main()
