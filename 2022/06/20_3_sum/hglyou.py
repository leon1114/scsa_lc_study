import unittest
from typing import *

class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        """
        Runtime: 3941 ms, faster than 19.64% of Python3 online submissions for 3Sum.
        Memory Usage: 17.2 MB, less than 91.33% of Python3 online submissions for 3Sum.
        """
        if len(nums) <= 2:
            return []

        if len(nums) == 3:
            return [nums] if sum(nums) == 0 else []
        
        nums.sort()

        answer = set()

        for i in range(len(nums) - 2):
            target = -nums[i]
            l, r = i + 1, len(nums) - 1

            while l < r:
                two_sum = nums[l] + nums[r]
                if two_sum == target:
                    triplet = (nums[i], nums[l], nums[r])
                    answer.add(triplet)
                    l += 1
                else:
                    if two_sum < target:
                        l += 1
                    else:
                        r -= 1
        
        return answer
                
                
class SolutionTests(unittest.TestCase):
    def test_example(self):
        self.assertEqual(Solution().threeSum([]), [])

        self.assertEqual(Solution().threeSum([0]), [])

        nums = [-1,0,1,2,-1,-4]
        answer = [[-1,-1,2],[-1,0,1]]
        result = Solution().threeSum(nums)
        self.assertEqual(result, answer)


if __name__ == '__main__':
    unittest.main()
