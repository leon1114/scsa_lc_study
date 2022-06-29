from typing import *
import unittest


class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        rows = []
        cols = []
        squares = []
        for i in range(9):
            if len(rows) <= i:
                rows.append(set())
            
            for j in range(9):
                if len(cols) <= j:
                    cols.append(set())
                
                square_num = j // 3 + (i // 3) * 3
                if len(squares) <= square_num:
                    squares.append(set())
                    
                num = board[i][j]
                
                if num in rows[i] or num in cols[j] or num in squares[square_num]:
                    return False
                else:
                    if num != '.':
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