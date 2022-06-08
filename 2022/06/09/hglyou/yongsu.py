from statistics import median
from typing import List

class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        # 쉽고 효율적이고 우아한 방식
        # return median(nums1 + nums2)

        # 알고리즘 스터디를 위한 방식
        ans = 0
        my_nums = [] # 두 개를 합칠 배열을 준비한다
        max_len = max(len(nums1), len(nums2)) # 두 개 중 큰 배열의 개수만큼 looping 한다
        for i in range(0, max_len):
            if i < len(nums1): # nums1의 개수만큼 배열에 넣는다
                my_nums.append(nums1[i])
            if i < len(nums2): # nums2의 개수만큼 배열에 넣는다
                my_nums.append(nums2[i])
        
        my_nums.sort() # Sorting은 파이썬에게 맡긴다

        if len(my_nums) % 2 == 0: # 짝수라면
            ans = (my_nums[len(my_nums) // 2 - 1] + my_nums[len(my_nums) // 2]) / 2.0 # 가운데 두 수의 평균
        else: # 홀수라면
            ans = my_nums[len(my_nums) // 2] # 가운데 수

        return ans