"""
Runtime: 58 ms, faster than 75.80% of Python3 online submissions for Find Peak Element.
Memory Usage: 14 MB, less than 82.49% of Python3 online submissions for Find Peak Element.
"""
class Solution:
    """
    local maximum 라도 상관없으니 찾기만하면 됨. 
    
    따라서 정렬되어있지 않은 array 지만 바이너리 서치로 찾을 수 있음. 
    """
    def findPeakElement(self, nums: List[int]) -> int:
        nums = [float('-inf')] + nums + [float('-inf')]
        l, r = 1, len(nums) - 2
        
        while l <= r:
            m = (l + r) // 2
            if nums[m] < nums[m+1]:
                l = m + 1
            elif nums[m-1] > nums[m]:
                r = m - 1
            else:
                # -inf 를 더해준 것 보정하여 return 
                return m - 1
                
