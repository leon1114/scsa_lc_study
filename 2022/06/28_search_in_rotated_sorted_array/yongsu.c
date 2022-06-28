#include <stdio.h>


// Runtime: 6 ms, faster than 44.46% of C online submissions for Search in Rotated Sorted Array.
// Memory Usage: 6.2 MB, less than 7.51% of C online submissions for Search in Rotated Sorted Array.

// 이진탐색인데 pivot 기준으로 값 비교하면서 탐색하기
// pivot 찾는 것도 이진탐색으로
int search(int* nums, int numsSize, int target){
    int i;
    int pivot = 0;
    int original_array[numsSize + 10];
    int left = 0;
    int right = numsSize - 1;
    int mid;

    while (left < right) {
        mid = (left + right) / 2;
        if (nums[mid] > nums[right]) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    pivot = left;

    left = 0;
    right = numsSize - 1;

    int real_mid;

    while (left <= right) {
        mid = (left + right) / 2;
        real_mid = mid + pivot > numsSize - 1 ? mid + pivot - numsSize : mid + pivot; 
        if (target == nums[real_mid]) {
            return real_mid;
        } else if (target < nums[real_mid]) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }   

    return -1; 
}

int main(void) {
    printf("%d\n", search((int []){4, 5, 6, 7, 0, 1, 2}, 7, 0)); // 4
    return 0;
}