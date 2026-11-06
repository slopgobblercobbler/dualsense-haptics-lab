import json
import os
import unittest

class TestDualSensePhaseAligner(unittest.TestCase):
    def setUp(self):
        p = os.path.join(os.path.dirname(__file__), '..', 'src', 'dualsense_haptic_phase_aligner.json')
        with open(p, 'r') as f:
            self.data = json.load(f)

    def test_phase_alignment(self):
        self.assertEqual(self.data['group_delay_ms'], 1.25)
        self.assertEqual(self.data['phase_jitter_tolerance_deg'], 5.0)

if __name__ == '__main__':
    unittest.main()
