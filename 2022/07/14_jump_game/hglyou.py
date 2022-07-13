class Solution:
    """
    O(n)
    Runtime: 639 ms, faster than 67.29% of Python3 online submissions for Jump Game.
    Memory Usage: 15.3 MB, less than 18.22% of Python3 online submissions for Jump Game.
    """
    def canJump(self, nums: List[int]) -> bool:
        destination = len(nums) - 1
        
        for i in reversed(range(len(nums) - 1)):
            if destination - i <= nums[i]:
                destination = i
        
        return destination == 0


    """
    O(n^2)
    Runtime: 3289 ms, faster than 10.24% of Python3 online submissions for Jump Game.
    Memory Usage: 15.1 MB, less than 82.21% of Python3 online submissions for Jump Game.
    """
    def canJumpOn2(self, nums: List[int]) -> bool:
        dp = [False for _ in range(len(nums))]
        dp[0] = True

        for i in range(1, len(nums)):
            for j in reversed(range(i)):
                if dp[j] and i - j <= nums[j]:
                    dp[i] = True
                    break
        return dp[-1]
