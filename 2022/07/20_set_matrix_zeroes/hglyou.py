class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        
        constant space 는 follow up 조건이므로 일단 O(m+n) 으로 풀어보기 
        
        Runtime: 148 ms, faster than 79.55% of Python3 online submissions for Set Matrix Zeroes.
        Memory Usage: 14.6 MB, less than 90.07% of Python3 online submissions for Set Matrix Zeroes.
        """
        
        rows_to_zero_out = set()
        cols_to_zero_out = set()
        
        for r in range(len(matrix)):
            for c in range(len(matrix[0])):
                
                if matrix[r][c] == 0:
                    rows_to_zero_out.add(r)
                    cols_to_zero_out.add(c)
                    
        
        for r in range(len(matrix)):
            for c in range(len(matrix[0])):
                
                if r in rows_to_zero_out or c in cols_to_zero_out:
                    matrix[r][c] = 0
