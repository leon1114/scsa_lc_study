class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        """
        
        path_cnts[r][c] = path_cnts[r-1][c] + path_cnts[r][c-1]
        
        Runtime: 33 ms, faster than 91.41% of Python3 online submissions for Unique Paths.
        Memory Usage: 13.9 MB, less than 73.29% of Python3 online submissions for Unique Paths.
        """
        
        if m == 1 or n == 1:
            return 1
    
        path_cnts = [1] * n
        
        for r in range(1, m):
            for c in range(n):
                left_cnt = 0 if c == 0 else path_cnts[c - 1]
                path_cnts[c] += left_cnt
                
        return path_cnts[-1]
