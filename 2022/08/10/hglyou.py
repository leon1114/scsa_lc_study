class Solution:
    """
    Runtime: 612 ms, faster than 5.03% of Python3 online submissions for Surrounded Regions.
    Memory Usage: 62.5 MB, less than 5.03% of Python3 online submissions for Surrounded Regions.
    """
    def solve(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
                
        dy = [-1, 0, 1, 0]
        dx = [0, 1, 0, -1]
        
        row_max = len(board)
        col_max = len(board[0])
        
        def dfs(r, c, members):
            if r < 0 or r >= row_max or c < 0 or c >= col_max:
                return False
            
            if board[r][c] == 'X':
                return True 
            
            members.add((r,c))
            
            is_surrounded = True
            for i in range(4):
                nr, nc = r + dy[i], c + dx[i]
                if (nr, nc) not in members:
                    res = dfs(nr, nc, members)
                    if not res:
                        return False
                    is_surrounded = is_surrounded and dfs(nr, nc, members)
                
            return is_surrounded
        
        for r in range(row_max):
            for c in range(col_max):
                if board[r][c] == 'X':
                    continue
                members = set()
                is_surrounded = dfs(r,c,members)
                if is_surrounded:
                    for row, col in members:
                        board[row][col] = 'X'
        
        return
                
                
