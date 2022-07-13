class Solution:
    """
    O(n^2)
    Runtime: 3289 ms, faster than 10.24% of Python3 online submissions for Jump Game.
    Memory Usage: 15.1 MB, less than 82.21% of Python3 online submissions for Jump Game.
    """
    def canJump(self, nums: List[int]) -> bool:
        dp = [False for _ in range(len(nums))]
        dp[0] = True

        for i in range(1, len(nums)):
            for j in reversed(range(i)):
                if dp[j] and i - j <= nums[j]:
                    dp[i] = True
                    break
        return dp[-1]
