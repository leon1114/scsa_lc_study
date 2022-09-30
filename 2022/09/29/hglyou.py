"""
Runtime: 1937 ms, faster than 62.95% of Python3 online submissions for Longest Increasing Subsequence.
Memory Usage: 14.2 MB, less than 82.45% of Python3 online submissions for Longest Increasing Subsequence.
"""

class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        """
        dp[n] -> n 번째 숫자를 마지막으로 하는 LIS 의 길이 
        dp[n] -> 1 + max(dp[0:n-1] | nums[i] < nums[n])
        
        일단 n^2 로 푼다
        """
        
        dp = [0] * len(nums)
        
        ans = -1
        for i in range(len(nums)):            
            max_prev_len = 0
            for j in range(i):
                if nums[j] < nums[i] and dp[j] > max_prev_len:
                    max_prev_len = dp[j]
            
            dp[i] = 1 + max_prev_len
            ans = max(ans, dp[i])
            
        return ans
        
