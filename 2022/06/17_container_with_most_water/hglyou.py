import unittest
from typing import *


class Solution:
    def bruteForce(self, height: List[int]) -> int:
        """
        Runtime: 8495 ms, faster than 5.03% of Python3 online submissions for Container With Most Water.
        Memory Usage: 26.1 MB, less than 99.54% of Python3 online submissions for Container With Most Water.

        time complexity = O(nm), where n == len(height), m == max(height)
        """
        min_h, max_h = min(height), max(height)

        max_area = -1

        for h in range(min_h, max_h + 1):
            l, r = 0, len(height) - 1

            while l < len(height) and height[l] < h:
                l += 1

            while r >= 0 and height[r] < h:
                r -= 1

            if l == len(height) or r < 0 or l == r:
                continue

            area = (r - l) * min(height[l], height[r])
            if area > max_area:
                max_area = area
        
        return max_area

    def twoPointer(self, height) -> int:
        """
        two pointer? 

        l, r 을 유지하면서 값이 더 작은쪽을 가운데 방향으로 움직인다.
        Runtime: 773 ms, faster than 90.56% of Python3 online submissions for Container With Most Water.
        Memory Usage: 27.5 MB, less than 54.27% of Python3 online submissions for Container With Most Water.
        """
        l, r = 0, len(height) - 1
        max_area = (r - l) * min(height[l], height[r])

        while l < r:
            if height[l] < height[r]:
                l += 1
            else:
                r -= 1
            area = (r - l) * min(height[l], height[r])
            max_area = max(area, max_area)

        return max_area

    def maxArea(self, height) -> int:
        return self.twoPointer(height)



class SolutionTests(unittest.TestCase):
    def setUp(self) -> None:
        self.sol = Solution()

    
    def test_solution(self):
        tc = [
            ([1,8,6,2,5,4,8,3,7], 49),
            ([1,1], 1),
            ([8,20,1,2,3,4,5,6], 42),
            ([8,10,14,0,13,10,9,9,11,11], 80),
        ]

        for idx, _tc in enumerate(tc):
            height, answer = _tc
            with self.subTest(idx=idx):
                result = self.sol.maxArea(height)
                self.assertEqual(result, answer)

if __name__ == "__main__":
    unittest.main()