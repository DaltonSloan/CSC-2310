import unittest
from shapeshifter2 import Shapeshifter


class TestShapeshifter(unittest.TestCase):

    def setUp(self):
        self.ssh = Shapeshifter('Human')
        self.ssw = Shapeshifter('Wolf')
        self.ssc = Shapeshifter('Crow')

    # Property Tests
    def test_form(self):
        self.assertEqual('Human', self.ssh.form)
        self.assertEqual('Wolf', self.ssw.form)
        self.assertEqual('Crow', self.ssc.form)

    def test_speak(self):
        self.assertEqual('Hello', self.ssh.speak)
        self.assertEqual('Howl', self.ssw.speak)
        self.assertEqual('Caw', self.ssc.speak)

    def test_arms(self):
        self.assertEqual(2, self.ssh.arms)
        self.assertEqual(0, self.ssw.arms)
        self.assertEqual(0, self.ssc.arms)

    def test_legs(self):
        self.assertEqual(2, self.ssh.legs)
        self.assertEqual(4, self.ssw.legs)
        self.assertEqual(2, self.ssc.legs)

    def test_wings(self):
        self.assertEqual(0, self.ssh.wings)
        self.assertEqual(0, self.ssw.wings)
        self.assertEqual(2, self.ssc.wings)

    def test_tail(self):
        self.assertFalse(self.ssh.tail)
        self.assertTrue(self.ssw.tail)
        self.assertTrue(self.ssc.tail)

    # Set Form Tests
    def test_set_human(self):
        self.ssw.form = 'Human'
        self.assertEqual('Human', self.ssw.form)
        self.assertEqual('Hello', self.ssw.speak)
        self.assertEqual(2, self.ssw.arms)
        self.assertEqual(2, self.ssw.legs)
        self.assertEqual(0, self.ssw.wings)
        self.assertFalse(self.ssw.tail)

    def test_set_wolf(self):
        self.ssh.form = 'Wolf'
        self.assertEqual('Wolf', self.ssh.form)
        self.assertEqual('Howl', self.ssh.speak)
        self.assertEqual(0, self.ssh.arms)
        self.assertEqual(4, self.ssh.legs)
        self.assertEqual(0, self.ssh.wings)
        self.assertTrue(self.ssh.tail)

    def test_set_crow(self):
        self.ssh.form = 'Crow'
        self.assertEqual('Crow', self.ssh.form)
        self.assertEqual('Caw', self.ssh.speak)
        self.assertEqual(0, self.ssh.arms)
        self.assertEqual(2, self.ssh.legs)
        self.assertEqual(2, self.ssh.wings)
        self.assertTrue(self.ssh.tail)

    # Exception Tests
    def test_created_invalid(self):
        invalid = ['Snake', 5, 5.0, [0, 1, 2], ['Human', 'Wolf', 'Crow'], True, None]
        for x in invalid:
            with self.assertRaises(Exception):
                self.ssn = Shapeshifter(x)

    def test_set_invalid(self):
        invalid = ['Snake', 5, 5.0, [0, 1, 2], ['Human', 'Wolf', 'Crow'], True, None]
        for x in invalid:
            with self.assertRaises(Exception):
                self.ssh.form = x

    def test_manual_bypass_form(self):
        invalid = ['Snake', 5, 5.0, [0, 1, 2], ['Human', 'Wolf', 'Crow'], True, None]
        for x in invalid:
            with self.assertRaises(Exception):
                self.ssh._Shapeshifter__form = x
                result = self.ssh.form

    def test_manual_bypass_speak(self):
        invalid = ['Snake', 5, 5.0, [0, 1, 2], ['Human', 'Wolf', 'Crow'], True, None]
        for x in invalid:
            with self.assertRaises(Exception):
                self.ssh._Shapeshifter__form = x
                result = self.ssh.speak

    def test_manual_bypass_arms(self):
        invalid = ['Snake', 5, 5.0, [0, 1, 2], ['Human', 'Wolf', 'Crow'], True, None]
        for x in invalid:
            with self.assertRaises(Exception):
                self.ssh._Shapeshifter__form = x
                result = self.ssh.arms

    def test_manual_bypass_legs(self):
        invalid = ['Snake', 5, 5.0, [0, 1, 2], ['Human', 'Wolf', 'Crow'], True, None]
        for x in invalid:
            with self.assertRaises(Exception):
                self.ssh._Shapeshifter__form = x
                result = self.ssh.legs

    def test_manual_bypass_wings(self):
        invalid = ['Snake', 5, 5.0, [0, 1, 2], ['Human', 'Wolf', 'Crow'], True, None]
        for x in invalid:
            with self.assertRaises(Exception):
                self.ssh._Shapeshifter__form = x
                result = self.ssh.wings

    def test_manual_bypass_tail(self):
        invalid = ['Snake', 5, 5.0, [0, 1, 2], ['Human', 'Wolf', 'Crow'], True, None]
        for x in invalid:
            with self.assertRaises(Exception):
                self.ssh._Shapeshifter__form = x
                result = self.ssh.tail


if __name__ == "__main__":
    unittest.main()
