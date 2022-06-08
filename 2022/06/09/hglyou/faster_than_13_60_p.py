from unittest import TestCase
import unittest
from typing import List

class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        """
        nums1, nums2 를 한 번씩만 순회하면서 정렬된 상태의 병합 리스트를 생성하고, 병합 리스트에서 중위값을 계산 
        O(n+m) solution

        Runtime: 185 ms, faster than 13.60% of Python3 online submissions for Median of Two Sorted Arrays.
        Memory Usage: 14.1 MB, less than 67.40% of Python3 online submissions for Median of Two Sorted Arrays.
        """

        nums1_idx = 0
        nums2_idx = 0

        nums = []
        while nums1_idx < len(nums1) and nums2_idx < len(nums2):
            num1 = nums1[nums1_idx]
            num2 = nums2[nums2_idx]

            if num1 <= num2:
                nums.append(num1)
                nums1_idx += 1
            else:
                nums.append(num2)
                nums2_idx += 1

        if nums1_idx < len(nums1):
            nums += nums1[nums1_idx:]

        if nums2_idx < len(nums2):
            nums += nums2[nums2_idx:]

        if len(nums) % 2 == 0:
            return (nums[len(nums)//2 - 1] + nums[len(nums)//2]) / 2
        else:
            return nums[len(nums)//2]


class SolutionTest(TestCase):
    def setUp(self):
        self.sol = Solution()

    def test_example_1(self):
        nums1 = [1,3]
        nums2 = [2]
        result = self.sol.findMedianSortedArrays(nums1, nums2)
        self.assertEqual(2.0, result)

    def test_example_2(self):
        nums1 = [1,2]
        nums2 = [3,4]
        result = self.sol.findMedianSortedArrays(nums1, nums2)
        self.assertEqual(2.5, result)

if __name__ == '__main__':
    unittest.main()