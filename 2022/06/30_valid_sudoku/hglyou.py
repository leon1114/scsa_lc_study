from typing import *
import unittest


class Solution:
    """
    Runtime: 94 ms, faster than 97.02% of Python3 online submissions for Valid Sudoku.
    Memory Usage: 13.9 MB, less than 34.46% of Python3 online submissions for Valid Sudoku.
    """
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        rows = [set() for _ in range(9)]
        cols = [set() for _ in range(9)]
        squares = [set() for _ in range(9)]
        for i in range(9):
            for j in range(9):
                num = board[i][j]
                if num == '.':
                    continue
                square_num = j // 3 + (i // 3) * 3                 
                if num in rows[i] or num in cols[j] or num in squares[square_num]:
                    return False
                else:
                    rows[i].add(num)
                    cols[j].add(num)
                    squares[square_num].add(num)
        return True
                    
                
class SolutionTests(unittest.TestCase):
    def test_example_1(self):
        sol = Solution()
        board = [["5","3",".",".","7",".",".",".","."]
                ,["6",".",".","1","9","5",".",".","."]
                ,[".","9","8",".",".",".",".","6","."]
                ,["8",".",".",".","6",".",".",".","3"]
                ,["4",".",".","8",".","3",".",".","1"]
                ,["7",".",".",".","2",".",".",".","6"]
                ,[".","6",".",".",".",".","2","8","."]
                ,[".",".",".","4","1","9",".",".","5"]
                ,[".",".",".",".","8",".",".","7","9"]]
        self.assertEqual(True, sol.isValidSudoku(board))


if __name__ == '__main__':
    unittest.main()