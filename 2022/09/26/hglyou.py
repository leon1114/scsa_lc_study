"""
Runtime: 3055 ms, faster than 55.65% of Python3 online submissions for Perfect Squares.
Memory Usage: 14.3 MB, less than 42.36% of Python3 online submissions for Perfect Squares.
"""

class Solution:
    def numSquares(self, n: int) -> int:
        """
        dp[n] -> 정답배열 : dp[n] = n 을 만들기 위한 최소한의 perfect num 갯수 
        """
        dp = [0 for _ in range(0, n+1)]        
        perfect_nums = [i**2 for i in range(1, n+1)]
        
        for num in range(1, n+1):
            global_min_cnt = inf
            for perfect_num in perfect_nums:
                if perfect_num > num:
                    break
                local_min_cnt = dp[num - perfect_num] + 1
                if local_min_cnt < global_min_cnt:
                    global_min_cnt = local_min_cnt
            dp[num] = global_min_cnt
                
        return dp[n]
