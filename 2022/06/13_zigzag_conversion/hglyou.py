import unittest
from typing import *

from collections import defaultdict
class Solution:
    """
    Runtime: 52 ms, faster than 96.09% of Python3 online submissions for Zigzag Conversion.
    Memory Usage: 13.9 MB, less than 75.19% of Python3 online submissions for Zigzag Conversion.

    takeaway: shortcircuit 조건이 있다면 무조건 찾아서 넣자
    """
    def convert(self, s: str, numRows: int) -> str:
        if numRows == 1 or numRows == len(s):
            return s

        rows_list = ['' for _ in range(numRows + 1)]
        row = 1
        diag = False

        for ch in s:
            rows_list[row] += ch
            if not diag:
                if row == numRows:
                    diag = True
                    row -= 1
                else:
                    row += 1
            else:
                if row == 1:
                    diag = False
                    row += 1
                else:
                    row -= 1
        
        return ''.join(rows_list)

class SolutionTest(unittest.TestCase):
    def setUp(self) -> None:
        self.sol = Solution()

    def test_examples(self):
        tc = [
            ("PAYPALISHIRING", 3, "PAHNAPLSIIGYIR"),
            ("PAYPALISHIRING", 4, "PINALSIGYAHRPI")
        ]

        for idx, _tc in enumerate(tc):
            s, numRows, answer = _tc
            with self.subTest(idx=idx):
                result = self.sol.convert(s, numRows)
                self.assertEqual(answer, result)


if __name__ == '__main__':
    unittest.main()