import unittest
from typing import *

from math import floor, ceil
class Solution:
    def rotate_allocate_new_list(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.

        제출전 제약조건 없이 푼 것
        """

        rows = len(matrix)
        cols = len(matrix[0])
        answer = [[0 for _ in range(cols)] for _ in range(rows)]

        for i in range(rows):
            for j in range(cols):
                num = matrix[i][j]
                next_col = rows - i - 1
                next_row = j
                answer[next_row][next_col] = num
                
        for i in range(rows):
            for j in range(cols):
                matrix[i][j] = answer[i][j]


    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.

        Runtime: 53 ms, faster than 51.06% of Python3 online submissions for Rotate Image.
        Memory Usage: 13.9 MB, less than 74.60% of Python3 online submissions for Rotate Image.
        """

        rows = len(matrix)
        cols = len(matrix[0])

        iter_rows = ceil(rows/2)
        for i in range(iter_rows):
            for j in range(i, cols - i - 1):
                cur_i = i
                cur_j = j

                for _ in range(3):
                    next_row = cur_j
                    next_col = rows - cur_i - 1
                    matrix[next_row][next_col], matrix[i][j] = matrix[i][j], matrix[next_row][next_col]
                    cur_i = next_row
                    cur_j = next_col


class SolutionTests(unittest.TestCase):
    def test_example(self):
        matrix = [[1,2,3],[4,5,6],[7,8,9]]
        Solution().rotate(matrix)
        self.assertEqual([[7,4,1],[8,5,2],[9,6,3]],matrix)

    def test_example_2(self):
        matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
        Solution().rotate(matrix)
        self.assertEqual([[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]], matrix)


if __name__ == '__main__':
    unittest.main()