class Solution:
    def rotate_O_n_space(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        
        Runtime: 211 ms, faster than 98.58% of Python3 online submissions for Rotate Array.
        Memory Usage: 25.5 MB, less than 29.10% of Python3 online submissions for Rotate Array.
        """
        
        k = k % len(nums)
        
        if k == 0 or len(nums) == 1:
            return nums
        
        _nums = nums[:]
        nums[:k] = _nums[-k:]
        nums[k:] = _nums[:-k]
        
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Runtime: 633 ms, faster than 22.94% of Python3 online submissions for Rotate Array.
        Memory Usage: 25.4 MB, less than 75.84% of Python3 online submissions for Rotate Array.
        """
        
        k = k % len(nums)
        if k == 0 or len(nums) == 1:
            return nums
        
        def in_place_reverse(array: List, s, e):
            while s < e:
                array[s], array[e] = array[e], array[s]
                s, e = s + 1, e - 1
        
        in_place_reverse(nums, 0, len(nums) - 1)
        in_place_reverse(nums, 0, k - 1)
        in_place_reverse(nums, k, len(nums) - 1)
        
