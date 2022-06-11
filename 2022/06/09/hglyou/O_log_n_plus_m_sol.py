from unittest import TestCase
import unittest
from typing import List

import math
class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        """
        중위값을 찾는 문제이므로, 두 list 를 완벽하게 정렬된 상태로 병합 할 필요가 없음.

        중위값의 왼쪽, 오른쪽에 각각 해당 값보다 작은 값들, 큰 값들이 잘 파티셔닝되어 모여 있기만 하면 됨.
        즉, 왼쪽, 오른쪽 파티션 내부에서는 값들이 정렬되어 있을 필요가 없다.

        위 조건을 충족하는 방식으로 잘 파티셔닝 된 병합 리스트를 만드는 방법:

        아래의 sample 을 예로 들자.
        nums1 = [1,2,5,6,7,8,9]
        nums2 = [1,2,3,4]

        두 list 의 병합 list 는 길이가 11 임. 병합 list 의 5번째 값을 기준으로 파티셔닝이 잘 이루어지면 됨.

        파티셔닝 방법:

        두 list 모두 이미 정렬이 되어 있는 상태이므로 각각 list 도 적절히 파티셔닝하여 왼쪽, 오른쪽 파티션끼리 병합하면 됨.
        또한, 병합 후 각 파티션의 길이는 이미 정해져있으므로 (5) 길이가 더 짧은 파티션에서 왼쪽 파티션을 정하면, 길이가 긴 list 의 왼쪽 파티션도
        함께 정해짐.
        즉, 길이가 더 짧은 파티션을 이용해 바이너리 서치로 적절한 왼쪽 파티션을 찾으면 됨.

        바이너리 서치 종료 조건은:
        nums1 왼쪽 파티션의 가장 큰 값이 nums2 오른쪽 파티션의 가장 작은 값 보다 작거나 같아야 함.
        nums2 왼쪽 파티션의 가장 큰 값이 nums1 오른쪽 파티션의 가장 작은 값 보다 작거나 같아야 함.

        예시)
        길이가 더 짧은 nums2 에서 먼저 왼쪽 파티션을 찾는다. 바이너리 서치 첫 시행이므로 단순히 nums2 의 절반을 나눠서 왼쪽 파티션을 정한다.
        >> nums2 에서는 [1,2] 를 왼쪽 파티션으로 사용하기로 함.

        nums2 에서 앞쪽 2개를 사용하기로 했으므로, nums1 에서는 앞쪽 3개를 왼쪽 파티션용으로 사용함
        >> nums1 의 [1,2,5]

        nums 1 = [1, 2, 5] [5,7,8,9]
        nums 2 = [1,2]     [3,4]

        첫 번째 서치에서는 바이너리 서치 종료 조건에 부합하지 않음 (nums1 왼쪽 파티션의 가장 큰 값 5 가 nums2 오른쪽 파티션의 가장 작은값 3보다 큼)

        첫 번째 서치에서 nums1의 왼쪽 파티션이 최적 조건보다 길었으므로, 두 번째 서치에서는 nums2 의 왼쪽 파티션을 더 길게 잡아야함.
        바이너리 서치의 l,r 이 0,4 에서 2, 4 로 변경 되어 nums2 의 세번째 값까지 왼쪽 파티션으로 사용한다.

        nums1 = [1,2] [5,5,7,8,9]
        nums2 = [1,2,3] [4]

        이제 바이너리 서치 종료 조건이 부합 하게 됨.

        각 파티션의 왼쪽 파티션들을 병합할 때는 각 왼쪽 파티션 중 최대값이 더 큰 파티션이 뒤쪽으로 가도록 병합,
        오른쪽 파티션들 병합시에는 최소값이 더 작은 파티션이 앞쪽으로 가도록 병합

        >> [1,2,1,2,3] [4,5,5,7,8,9]

        중위값 4가 된다.
        """

        # 더 짧은 list 가 nums1 이 되도록 설정
        if len(nums1) > len(nums2):
            nums1, nums2 = nums2, nums1

        # 병합된 리스트의 총 길이
        len_merged = len(nums1) + len(nums2)

        # 병합된 리스트에서 각 파티션의 길이
        len_left = len_merged // 2
        len_right = len_merged // 2 + len_merged % 2

        # 바이너리 서치용 변수 선언
        l, r = 0, len(nums1) # right 는 exclusive

        while True:
            m = (l + r) // 2
            end_of_left_partition_idx = m

            nums1_left_max_idx = end_of_left_partition_idx - 1
            nums2_left_max_idx = len_left - end_of_left_partition_idx - 1
            nums1_right_min_idx = end_of_left_partition_idx
            nums2_right_min_idx = len_left - end_of_left_partition_idx

            nums1_left_part_max = nums1[nums1_left_max_idx] if nums1_left_max_idx >= 0 else -math.inf
            nums2_left_part_max = nums2[nums2_left_max_idx] if nums2_left_max_idx >= 0 else -math.inf
            nums1_right_part_min = nums1[nums1_right_min_idx] if nums1_right_min_idx < len(nums1) else math.inf
            nums2_right_part_min = nums2[nums2_right_min_idx] if nums2_right_min_idx < len(nums2) else math.inf

            if nums1_left_part_max <= nums2_right_part_min and nums2_left_part_max <= nums1_right_part_min:
                # 적절한 partition 을 찾음
                if len_merged % 2 == 0:
                    # 중위값 계산을 위해 왼쪽 파티션의 최대값과 오른쪽 파티션의 최소값의 평균 구해야 하는 경우
                    return (max(nums1_left_part_max, nums2_left_part_max) + min(nums1_right_part_min, nums2_right_part_min)) / 2
                else:
                    # 중위값 계산위해 오른쪽 파티션의 최소값을 사용하면 되는 경우
                    return min(nums1_right_part_min, nums2_right_part_min)
            else:
                if nums1_left_part_max > nums2_right_part_min:
                    # nums1 이 더 짧아져야 하는 경우
                    r = m
                else:
                    # nums1 이 더 길어져야 하는 경우
                    l = m + 1


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

    def test_example_3(self):
        nums1 = []
        nums2 = [1]
        result = self.sol.findMedianSortedArrays(nums1, nums2)
        self.assertEqual(1, result)

if __name__ == '__main__':
    unittest.main()
