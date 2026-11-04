import json
import os
import unittest

class TestAudioDeviceRouting(unittest.TestCase):
    def setUp(self):
        p = os.path.join(os.path.dirname(__file__), '..', 'src', 'audio_device_routing.json')
        with open(p, 'r') as f:
            self.data = json.load(f)

    def test_endpoints(self):
        self.assertEqual(self.data['ENDPOINT_HEADSET'], 0x01)
        self.assertEqual(self.data['ENDPOINT_HAPTICS'], 0x08)

if __name__ == '__main__':
    unittest.main()
