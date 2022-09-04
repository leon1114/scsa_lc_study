"""
Runtime: 259 ms, faster than 82.78% of Python3 online submissions for Rotate Array.
Memory Usage: 25.4 MB, less than 29.10% of Python3 online submissions for Rotate Array.
"""

class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        if k == 0 or k % len(nums) == 0 or len(nums) == 1:
            return nums
        
        k = k % len(nums)
        
        _nums = nums[:]
        nums[:k] = _nums[-k:]
        nums[k:] = _nums[:-k]
