import unittest
from typing import * 


class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        return None


class SolutionTest(unittest.TestCase):
    def setUp(self):
        self.sol = Solution()

    def test_example(self):
        tc = [
            ("aa", "a", False),
            ("aa", "a*", True),
            ("ab", ".*", True)
        ]

        for idx, _tc in enumerate(tc):
            with self.subTest(idx=idx):
                s, p, answer = _tc
                result = self.sol.isMatch(s, p)
                self.assertEqual(result, answer)

if __name__ == "__main__":
    unittest.main()