"""
Runtime: 211 ms, faster than 98.58% of Python3 online submissions for Rotate Array.
Memory Usage: 25.5 MB, less than 29.10% of Python3 online submissions for Rotate Array.
"""

class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        
        k = k % len(nums)
        
        if k == 0 or len(nums) == 1:
            return nums
        
        _nums = nums[:]
        nums[:k] = _nums[-k:]
        nums[k:] = _nums[:-k]
