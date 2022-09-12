from functools import cmp_to_key

"""
Runtime: 40 ms, faster than 95.13% of Python3 online submissions for Largest Number.
Memory Usage: 13.9 MB, less than 22.17% of Python3 online submissions for Largest Number.
"""

class Solution:
    def largestNumber(self, nums: List[int]) -> str:
        nums = [str(num) for num in nums]
        nums.sort(key=cmp_to_key(lambda x,y: 1 if x+y > y+x else -1), reverse=True)
        ans = ''.join(nums)
        return ans if int(ans) != 0 else '0'
