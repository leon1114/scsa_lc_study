class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        '''
        Runtime: 922 ms, faster than 91.28% of Python3 online submissions for First Missing Positive.
        Memory Usage: 69.8 MB, less than 14.39% of Python3 online submissions for First Missing Positive.
        Easy peasy lemon squeezy - just use hashmap
        '''
        num_set = set()
        for num in nums:
            num_set.add(num)
        
        target = 1
        while True:
            if target in num_set:
                target += 1
            else:
                return target
