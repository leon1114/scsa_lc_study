class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        """
        Runtime: 850 ms, faster than 78.37% of Python3 online submissions for Maximum Subarray.
        Memory Usage: 28.6 MB, less than 9.80% of Python3 online submissions for Maximum Subarray.
        """
        tmp_max = float('-inf')
        _max = float('-inf')
        
        for num in nums:
            tmp_max = max(num, num + tmp_max)
            _max = max(_max, tmp_max)
        
        return _max
