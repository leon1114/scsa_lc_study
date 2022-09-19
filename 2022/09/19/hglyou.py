"""
Runtime: 536 ms, faster than 95.88% of Python3 online submissions for Kth Largest Element in an Array.
Memory Usage: 27.4 MB, less than 40.78% of Python3 online submissions for Kth Largest Element in an Array.
"""

class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        
        nums_count = [0] * 20001
        
        for num in nums:
            nums_count[num + 10000] += 1
        print(nums_count[10001:10007])
        
        for idx in reversed(range(len(nums_count))):
            count = nums_count[idx]
            num = idx - 10000
            k -= count
            if k <= 0:
                return num
