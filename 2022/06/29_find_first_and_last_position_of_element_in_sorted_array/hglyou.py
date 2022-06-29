class Solution:
    def bisect(self, nums: List[int], target: int, bisect_left: bool) -> int:
        l, r = 0, len(nums) - 1
        while l <= r:
            m = (l + r) // 2
            
            if nums[m] == target:
                if bisect_left:
                    if m == l or nums[m - 1] < target:
                        return m
                    r = m - 1
                else: # bisect_right
                    if m == r or nums[m + 1] > target:
                        return m
                    l = m + 1
            elif nums[m] > target:
                r = m - 1
            else:
                l = m + 1
        
        return -1
    
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        
        l = self.bisect(nums, target, True)
        if l == -1:
            return [-1, -1]
        
        r = self.bisect(nums, target, False)
        
        return [l, r]
        
