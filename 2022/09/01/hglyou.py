"""
Runtime: 4287 ms, faster than 12.33% of Python3 online submissions for Factorial Trailing Zeroes.
Memory Usage: 13.9 MB, less than 21.75% of Python3 online submissions for Factorial Trailing Zeroes.
"""

class Solution:
    def trailingZeroes(self, n: int) -> int:
        if n == 0 :
            return 0
        
        fac = 1
        
        for i in range(1, n+1):
            fac *= i
        
        fac = str(fac)
        fac_len = len(fac)
        
        return fac_len - len(fac.rstrip('0'))
