#include <stdio.h>


// Runtime: 19 ms, faster than 16.56% of C online submissions for Find First and Last Position of Element in Sorted Array.
// Memory Usage: 7.7 MB, less than 12.30% of C online submissions for Find First and Last Position of Element in Sorted Array.

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize){
    *returnSize = 2;

    int *ans = (int *)malloc(2 * sizeof(int));
    int first_idx = -1;
    int last_idx = -1;

    int pivot = -1;

    ans[0] = first_idx;
    ans[1] = last_idx;

    int left = 0;
    int right = numsSize - 1;
    int mid;

    while (left <= right) {
        mid = (left + right) / 2;
        if (target == nums[mid]) {
            pivot = mid;
            break;
        } else if (target < nums[mid]) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    
    if (pivot != -1) {
        first_idx = last_idx = pivot;
        while (first_idx >= 0 && nums[first_idx] == target) first_idx--;
        while (last_idx <= numsSize - 1 && nums[last_idx] == target) last_idx++;
        ans[0] = first_idx + 1;
        ans[1] = last_idx - 1;
    }

    for (int i = 0; i < 2; i++) {
        printf("%d ", ans[i]);
    }

    printf("\n");

    return ans;
}

int main(void) {
    int returnSize;
    searchRange((int[]){5,7,7,8,8,10}, 6, 8, &returnSize);
    searchRange((int[]){1}, 1, 1, &returnSize);
    return 0;
}