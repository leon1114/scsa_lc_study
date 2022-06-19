from typing import List
import unittest

# Runtime: 9924 ms, faster than 5.00% of Python3 online submissions for 3Sum.
# Memory Usage: 18 MB, less than 71.84% of Python3 online submissions for 3Sum.

"""
배열 C로 관리하기 어려워서 python으로 함.. C 나중에 연습하자
"""

"""
1. 오름차순으로 정렬
2. 숫자를 고정
3. 두 개의 인덱스 (left right)를 통해 합이 0이 되는 조합을 찾는다 (left가 right와 같을때까지) 이때 left i를 제외한 가장 왼쪽부터, right는 가장 오른쪽부터 시작
4. 이 때, 배열이 오름차순이기 때문에 세 수의 합이 0보다 작으면 무조건 left를 한 칸 이동한다. 반대로 세 수의 합이 0보다 크면 right를 한 칸 땡긴다
5. 중복 제거를 위해 다음 숫자가 같으면 한 칸씩 더 땡긴다 (아이디어만 생각했는데 버그를 못잡아서 이미 있는 조합이면 안 넣는 것으로 변경)
"""
class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        ans = []
        nums.sort()

        for i in range(len(nums) - 2):
            left = i + 1
            right = len(nums) - 1
            while left < right:
                sum = nums[i] + nums[left] + nums[right]
                if sum < 0:
                    left += 1
                elif sum > 0:
                    right -= 1
                else:
                    tmp = [nums[i], nums[left], nums[right]]
                    if tmp not in ans:
                        ans.append(tmp)
                    left += 1
                    right -= 1

        return ans


class SolutionTests(unittest.TestCase):
    def setUp(self) -> None:
        self.sol = Solution()

    def test_1(self):
        nums = [-1, 0, 1, 2, -1, -4]
        answer = [[-1, -1, 2], [-1, 0, 1]]
        result = self.sol.threeSum(nums)
        self.assertEqual(result, answer)


if __name__ == "__main__":
    unittest.main()