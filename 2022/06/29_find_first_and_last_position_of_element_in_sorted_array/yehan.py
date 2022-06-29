class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        '''
        Runtime: 105 ms, faster than 70.79% of Python3 online submissions for Find First and Last Position of Element in Sorted Array.
        Memory Usage: 15.5 MB, less than 10.28% of Python3 online submissions for Find First and Last Position of Element in Sorted Array.
        이진탐색 먼저해서 찾은담에 걍 양옆을 뒤져서 left right index 찾음'''
        left, mid = 0, 0
        right = len(nums) - 1
        found = False
        
        while left <= right:
            mid = (left + right) // 2
            if nums[mid] == target:
                found = True
                break
            
            if nums[mid] < target:
                left = mid + 1
            else:
                right = mid - 1
                
        if not found:
            return [-1, -1]
        
        left = right = mid
        
        while left - 1 >= 0:
            if nums[left - 1] == target:
                left -= 1
            else:
                break
            
        while right + 1 < len(nums):
            if nums[right + 1] == target:
                right += 1
            else:
                break
        
        return [left, right]
