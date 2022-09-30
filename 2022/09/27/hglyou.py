"""
Runtime: 1722 ms, faster than 9.65% of Python3 online submissions for Find the Duplicate Number.
Memory Usage: 27.8 MB, less than 91.21% of Python3 online submissions for Find the Duplicate Number.
"""


"""
nums 를 flag 배열로 사용하는 방법 
"""
class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        repeated = None
        for num in nums:
            cur = abs(num)
            
            if nums[cur] < 0:
                repeated = cur
                break
            else:
                nums[cur] = -nums[cur]
                
        for idx in range(len(nums)):
            nums[idx] = abs(nums[idx])
            
        return repeated
