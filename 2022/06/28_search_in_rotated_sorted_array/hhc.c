// Runtime: 4 ms, faster than 61.29% of C online submissions for Search in Rotated Sorted Array.
// Memory Usage: 5.9 MB, less than 97.57% of C online submissions for Search in Rotated Sorted Array.
// 이왜진? 이왜진?? 이게~ 왜~ 쥔쫘~~~~?

int search(int* nums, int numsSize, int target){
    int index = -1;
    for(int i = 0; i < numsSize; i++) {
        if (nums[i] == target) index = i;
    }
    return index;
}
