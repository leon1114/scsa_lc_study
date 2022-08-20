class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        """
        O(1) 으로 membership check 하기 위해 hash set 을 활용함. 
        
        Runtime: 429 ms, faster than 81.01% of Python3 online submissions for Longest Consecutive Sequence.
        Memory Usage: 28.7 MB, less than 39.51% of Python3 online submissions for Longest Consecutive Sequence.
        
        """        
        nums_set = set(nums)
        max_len = 0
        
        for num in nums:
            if num not in nums_set:
                continue
            
            nums_set.remove(num)
            left = num - 1
            while left in nums_set:
                nums_set.remove(left)
                left -= 1
            
            right = num + 1
            while right in nums_set:
                nums_set.remove(right)
                right += 1
                
            max_len = max(max_len, right - left - 1)
            
        return max_len
