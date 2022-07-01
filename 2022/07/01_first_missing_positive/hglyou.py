class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        """
        Runtime: 1613 ms, faster than 20.16% of Python3 online submissions for First Missing Positive.
        Memory Usage: 63.3 MB, less than 42.73% of Python3 online submissions for First Missing Positive.
        """
        
        if 1 not in nums:
            return 1
        
        for i, num in enumerate(nums):
            if num <= 0:
                nums[i] = 1
        print(nums)
        for i, num in enumerate(nums):
            val = abs(num)
            if val > len(nums):
                continue
            if val == len(nums):
                nums[0] = -abs(nums[0])
            else:
                nums[val] = -abs(nums[val])
        print(nums)
        for i in range(1, len(nums)):
            if nums[i] > 0:
                return i
            
        if nums[0] > 0:
            return len(nums)
        else:
            return len(nums) + 1
            
            
                
        
            