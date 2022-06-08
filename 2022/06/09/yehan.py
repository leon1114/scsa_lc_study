class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        '''
        Runtime: 130 ms, faster than 48.67% of Python3 online submissions for Median of Two Sorted Arrays.
Memory Usage: 14.2 MB, less than 67.40% of Python3 online submissions for Median of Two Sorted Arrays.
왜 accept 되지;;
        '''

        total_list = nums1 + nums2
        total_list.sort()

        if len(total_list) % 2:
            ans = total_list[len(total_list) // 2]
        else:
            ans = (total_list[len(total_list) // 2 - 1] + total_list[len(total_list) // 2]) / 2
        return ans