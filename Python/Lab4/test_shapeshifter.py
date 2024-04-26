import unittest
from shapeshifter import Shapeshifter


class TestShapeshifter(unittest.TestCase):
    def setUp(self):
        self.ssh = Shapeshifter('Human')
        self.ssw = Shapeshifter('Wolf')
        self.ssc = Shapeshifter('Crow')

    # Property Tests
    def test_form(self):
        self.assertEqual(self.ssh.form, 'Human')
        self.assertEqual(self.ssw.form, 'Wolf')
        self.assertEqual(self.ssc.form, 'Crow')

    def test_speak(self):
        self.assertEqual(self.ssh.speak(), 'Hello')
        self.assertEqual(self.ssw.speak(), 'Howl')
        self.assertEqual(self.ssc.speak(), 'Caw')

    def test_arms(self):
        self.assertEqual(self.ssh.arms, 2)
        self.assertEqual(self.ssw.arms, 0)
        self.assertEqual(self.ssc.arms, 0)

    def test_legs(self):
        self.assertEqual(self.ssh.legs, 2)
        self.assertEqual(self.ssw.legs, 4)
        self.assertEqual(self.ssc.legs, 2)

    def test_wings(self):
        self.assertEqual(self.ssh.wings, 0)
        self.assertEqual(self.ssw.wings, 0)
        self.assertEqual(self.ssc.wings, 2)

    def test_tail(self):
        self.assertFalse(self.ssh.tail)
        self.assertTrue(self.ssw.tail)
        self.assertTrue(self.ssc.tail)

    # Set form Tests
    def test_set_human(self):
        self.ssw.form = 'Human'
        self.assertEqual(self.ssw.form, 'Human')
        self.assertEqual(self.ssw.speak, 'Hello')
        self.assertEqual(self.ssw.arms, 2)
        self.assertEqual(self.ssw.legs, 2)
        self.assertEqual(self.ssw.wings, 0)
        self.assertFalse(self.ssw.tail)

    def test_set_wolf(self):
        self.ssh.form = 'Wolf'
        self.assertEqual(self.ssh.form, 'Wolf')
        self.assertEqual(self.ssh.speak, 'Howl')
        self.assertEqual(self.ssh.arms, 0)
        self.assertEqual(self.ssh.legs, 4)
        self.assertEqual(self.ssh.wings, 0)

    def test_set_crow(self):
        self.ssh.form = 'Crow'
        self.assertEqual(self.ssh.form, 'Crow')
        self.assertEqual(self.ssh.speak, 'Caw')
        self.assertEqual(self.ssh.arms, 0)
        self.assertEqual(self.ssh.legs, 2)
        self.assertEqual(self.ssh.wings, 2)
        self.assertTrue(self.ssh.tail)

    # Test Invalid Input
    def test_created_invalid(self):
        invalid = ['Dragon', 5, 5.0, True, False, None, [], {}]
        for x in invalid:
            with self.assertRaises(Exception):
                self.ssn = Shapeshifter(x)

    def test_set_invalid(self):
        invalid = ['Dragon', 5, 5.0, True, False, None, [], {}]
        for x in invalid:
            with self.assertRaises(Exception):
                self.ssh.form = x

    # Test Manuel Bypass
    def test_manuel_bypass_speech(self):
        invalid = ['Dragon', 5, 5.0, True, False, None, [], {}]
        for x in invalid:
            with self.assertRaises(Exception):
                self.ssh._ShapeShifter__form = x
                result = self.ssh.speak
                result = self.ssh.arms
                result = self.ssh.legs
                result = self.ssh.wings
                result = self.ssh.tail
