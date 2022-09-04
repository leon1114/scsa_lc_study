from collections import deque
"""
Runtime: 346 ms, faster than 84.93% of Python3 online submissions for Number of Islands.
Memory Usage: 16.4 MB, less than 81.30% of Python3 online submissions for Number of Islands.
"""
class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        cnt = 0
        
        rows, cols = len(grid), len(grid[0])
        
        def dfs(r,c):
            if (r < 0 or r >= rows or c < 0 or c >= cols or grid[r][c] == '0'):
                return
            
            grid[r][c] = '0'
            
            dfs(r+1, c)
            dfs(r-1, c)
            dfs(r, c+1)
            dfs(r, c-1)
        
        for r in range(rows):
            for c in range(cols):  
                if grid[r][c] == '1':
                    cnt += 1
                    dfs(r,c)

        return cnt
