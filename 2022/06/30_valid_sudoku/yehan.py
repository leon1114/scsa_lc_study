class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        '''
        Runtime: 127 ms, faster than 64.13% of Python3 online submissions for Valid Sudoku.
        Memory Usage: 14 MB, less than 6.22% of Python3 online submissions for Valid Sudoku.
        조건마다 중복 체크해서 해결하기'''
        for row in board:
            row = [x for x in row if x != '.']
            if len(set(row)) != len(row):
                print("row")
                return False
        
        pivoted_board = list(zip(*board[::-1]))
        
        for row in pivoted_board:
            row = [x for x in row if x != '.']
            if len(set(row)) != len(row):
                print("column")
                return False
            
        for i in range(3):
            for j in range(3):
                ii = i * 3
                jj = j * 3
                sub_list = [board[iii][jj:jj+3] for iii in range(ii, ii+3)]
                row = []
                for x in range(3):
                    for y in range(3):
                        row.append(sub_list[x][y])
                row = [x for x in row if x != '.']
                if len(set(row)) != len(row):
                    print("WTF")
                    return False
                
        return True
                
