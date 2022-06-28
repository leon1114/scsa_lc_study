class Solution:
    def search(self, nums: List[int], target: int) -> int:
#  o(n) solution
#         for idx, num in enumerate(nums):
#             if num == target:
#                 return idx
#         return -1
 
        '''
        Runtime: 47 ms, faster than 84.04% of Python3 online submissions for Search in Rotated Sorted Array.
        Memory Usage: 14.3 MB, less than 56.31% of Python3 online submissions for Search in Rotated Sorted Array.'''
        left, right = 0, len(nums) - 1
        
        while left <= right:
            mid = (right + left) // 2
            if nums[mid] == target:
                return mid
            
            if nums[left] <= nums[mid]:
                if nums[left] <= target < nums[mid]:
                    right = mid - 1
                else:
                    left = mid + 1
                
            else:
                if nums[mid] < target <= nums[right]:
                    left = mid + 1
                else:
                    right = mid - 1
        return -1
    
