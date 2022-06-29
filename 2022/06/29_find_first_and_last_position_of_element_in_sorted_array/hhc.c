// Runtime: 6 ms, faster than 96.07% of C online submissions for Find First and Last Position of Element in Sorted Array.
// Memory Usage: 7.4 MB, less than 81.15% of C online submissions for Find First and Last Position of Element in Sorted Array.
int binarySearch(int* nums, int left, int right, int target) {
    int mid = (left + right) / 2;
    if (target == nums[mid]) return mid;
    else if (left == right) return -1;
    else if (target < nums[mid]) {
        return binarySearch(nums, left, mid, target);
    } else {
        return binarySearch(nums, mid + 1, right, target);
    }
}

int lowerBoundarySearch(int* nums, int left, int right, int target) {
    int mid = (left + right) / 2;
    if (target == nums[mid] && (mid - 1 >= left && target > nums[mid - 1] || mid == left)) return mid;
    else if (left == right) return -1;
    else if (target > nums[mid]) {
        return lowerBoundarySearch(nums, mid + 1, right, target);
    }
    else {
        return lowerBoundarySearch(nums, left, mid, target);
    } 
}

int upperBoundarySearch(int* nums, int left, int right, int target) {
    int mid = (left + right) / 2;
    if (target == nums[mid] && (mid + 1 <= right && target < nums[mid + 1] || mid == right)) return mid;
    else if (left == right) return -1;
    else if (target < nums[mid]) {
        return upperBoundarySearch(nums, left, mid, target);
    } else {
        return upperBoundarySearch(nums, mid + 1, right, target);
    }
}


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize){
    int left = 0, right = numsSize - 1;
    int mid = -1;
    *returnSize = 2;
    int * ret = (int*)malloc(sizeof(int) * 2);
    ret[0] = -1; ret[1] = -1;
    if (numsSize == 0) return ret;
    ret[0] = binarySearch(nums, left, right, target);
    if (ret[0] == -1) return ret;
    ret[0] = lowerBoundarySearch(nums, left, ret[0], target);
    ret[1] = upperBoundarySearch(nums, ret[0], right, target);    
    return ret;
}
