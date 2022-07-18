from collections import deque

class Solution:
    """
    Runtime: 6746 ms, faster than 63.51% of Python3 online submissions for Word Search.
    Memory Usage: 13.9 MB, less than 50.90% of Python3 online submissions for Word Search.
    """
    def exist(self, board: List[List[str]], word: str) -> bool:
        directions = [(1,0), (0, -1), (-1, 0), (0, 1)]
        def dfs(s_r, s_c, target_idx, visited):
            if target_idx == len(word) - 1 and board[s_r][s_c] == word[target_idx]:
                return True
            
            if board[s_r][s_c] != word[target_idx]:
                return False
            
            for dy, dx in directions:
                ny, nx = s_r + dy, s_c + dx
                if ny < 0 or ny >= len(board) or nx < 0 or nx >= len(board[0]):
                    continue
                
                if (ny, nx) in visited:
                    continue
                
                if board[ny][nx] != word[target_idx+1]:
                    continue
                
                visited.add((ny, nx))
                result = dfs(ny, nx, target_idx + 1, visited)
                visited.remove((ny, nx))
                
                if result:
                    return True
            
            return False 
            
        for r in range(len(board)):
            for c in range(len(board[0])):
                if board[r][c] == word[0]:                 
                    result = dfs(r,c, 0, set([(r,c)]))
                    if result:
                        return True
        
        return False
