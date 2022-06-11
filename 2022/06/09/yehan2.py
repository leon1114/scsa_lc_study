class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        '''
        Runtime: 130 ms, faster than 49.73% of Python3 online submissions for Median of Two Sorted Arrays.
Memory Usage: 14.3 MB, less than 24.73% of Python3 online submissions for Median of Two Sorted Arrays.

동일한 사이즈의 두 파티션을 나눈다. 나누는 기준을 첨에 첫번째 배열의 중간값으로 잡아 왼쪽 값이 오른쪽보다 작은지 확인하고, 만약 아니면 인덱스를 바꿔 다시 확인한다.
만약 첫번째 배열의 왼쪽 파티션이 두번째 배열의 오른쪽 배열보다 크다면, 기준점을 현 기준의 -1 부터 잡아 다시 탐색한다.
        '''
        total_length = len(nums1 + nums2)
        half = total_length // 2
        
        if len(nums2) < len(nums1):
            nums1, nums2 = nums2, nums1
        
        l, r = 0, len(nums1) - 1
        while True:
            nums1_idx = (l + r) // 2 
            nums2_idx = half - nums1_idx - 2 
        
            nums1_left = nums1[nums1_idx] if nums1_idx >= 0 else float("-infinity")
            nums1_right = nums1[nums1_idx + 1] if (nums1_idx + 1) < len(nums1) else float("infinity")
            nums2_left = nums2[nums2_idx] if nums2_idx >= 0 else float("-infinity")
            nums2_right = nums2[nums2_idx + 1] if (nums2_idx + 1) < len(nums2) else float("infinity")
        
            if nums1_left <= nums2_right and nums2_left <= nums1_right:
                if total_length % 2:
                    return min(nums1_right, nums2_right)
                else:
                    return (max(nums1_left, nums2_left) + min(nums1_right, nums2_right)) / 2
            elif nums1_left > nums2_right:
                r = nums1_idx - 1
            else:
                l = nums1_idx + 1
