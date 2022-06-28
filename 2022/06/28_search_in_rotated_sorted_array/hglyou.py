from bisect import bisect_left
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        if nums[0] > nums[-1]:
            l, r = 0, len(nums) - 1
            while l <= r:
                m = (l + r) // 2
                if nums[m] > nums[m+1]:
                    split_idx = m+1
                    break
                else:
                    if nums[l] > nums[m]:
                        r = m - 1
                    else:
                        l = m + 1
        else:
            split_idx = 0
                
        if target == nums[split_idx]:
            return split_idx
        else:
            if split_idx == 0:
                target_idx = bisect_left(nums, target)
            else:    
                if target < nums[0]:
                    target_idx = bisect_left(nums[split_idx:], target) + split_idx
                    print(target_idx)
                else:
                    target_idx = bisect_left(nums[:split_idx], target)
    
            
            return target_idx if target_idx < len(nums) and nums[target_idx] == target else -1
            
                    
                
        