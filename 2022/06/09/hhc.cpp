#include <stdio.h>

// Runtime: 26 ms, faster than 34.07% of C online submissions for Median of Two Sorted Arrays.
// Memory Usage: 6.4 MB, less than 70.14% of C online submissions for Median of Two Sorted Arrays.

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    double median = 0;
    int full_size = nums1Size + nums2Size;
    int is_odd = full_size % 2;
    int med_idx = (full_size + 1) / 2 - 1;
    int it = 0;
    int it1 = 0;
    int it2 = 0;
    int last = 0;
    // printf("med_idx %d\n", med_idx);
    // case: m or n is 0
    if (!nums1Size || !nums2Size){
        if (!nums1Size) {
            if (is_odd) {
                median = (double)nums2[med_idx];
            } else {
                median = (nums2[med_idx] + nums2[med_idx + 1]) / 2.0;
            }
        } else {
            if (is_odd) {
                median = (double)nums1[med_idx];
            } else {
                median = (nums1[med_idx] + nums1[med_idx + 1]) / 2.0;
            }
        }
        return median;
    }
    for(; it1 < nums1Size && it <= med_idx;)
    {
        if (it2 < nums2Size && nums2[it2] < nums1[it1]) {
            for(; it2 < nums2Size && nums2[it2] < nums1[it1] && it <= med_idx;)
            {
                last = nums2[it2];
                it++; it2++;
                // printf("num2 added %d / it = %d\n", last, it);
            }
        }
        if (it > med_idx) break;
        last = nums1[it1];
        it++; it1++;
        // printf("num1 added %d / it = %d\n", last, it);
    }
    if (it2 < nums2Size && it <= med_idx) {
        for(; it2 < nums2Size && it <= med_idx;)
        {
            last = nums2[it2];
            it2++; it++;
            // printf("num2 added %d / it = %d\n", last, it);
        }
    }
    // case: full_size odd(return last one) or even(return last one + right next one)
    if (is_odd) {
        median = (double)last;
    } else {
        int smaller = last;
        if (it1 >= nums1Size) smaller = nums2[it2];
        else if (it2 >= nums2Size) smaller = nums1[it1];
        else if (nums1[it1] < nums2[it2]) smaller = nums1[it1];
        else smaller = nums2[it2];
        median = (last + smaller) / 2.0;
    }
    return median;
}


int main()
{
    int nums1[] = {1,2};
    int nums2[] = {-1,3};
    double d = findMedianSortedArrays(nums1, 2, nums2, 2);
    printf("answer 1.5: %.6f\n", d);
    
    
    int nums3[] = {1};
    int nums4[] = {2,3};
    double d3 = findMedianSortedArrays(nums3, 1, nums4, 2);
    printf("answer 2: %.6f\n", d3);
    
    int nums5[] = {3};
    int nums6[] = {-2,-1};
    double d5 = findMedianSortedArrays(nums5, 1, nums6, 2);
    printf("answer -1: %.6f\n", d5);
    
    int nums7[] = {};
    int nums8[] = {-1,2};
    double d7 = findMedianSortedArrays(nums7, 0, nums8, 2);
    printf("answer 0.5: %.6f\n", d7);
    
    int nums9[] = {2,3,4,5};
    int nums10[] = {1};
    double d9 = findMedianSortedArrays(nums9, 4, nums10, 1);
    printf("answer 3: %.6f\n", d9);
    return 0;
}

