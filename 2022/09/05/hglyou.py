"""
Runtime: 47 ms, faster than 58.23% of Python3 online submissions for House Robber.
Memory Usage: 13.8 MB, less than 97.20% of Python3 online submissions for House Robber.
"""

class Solution:
    def rob(self, nums: List[int]) -> int:
        """
        모든 경우의 수 고려해봐야 하고, 
        
        이전 집 status => 이전 집을 털었을경우 gain, 안 털었을 경우 gain 이 저장되어 있어야 함. 
        """
        dp = [nums[0], 0] # 해당 index의 집 털기, 안털기
        
        for num in nums[1:]:
            dp = [dp[1] + num, max(dp[0], dp[1])]
        
        return max(dp)
        
