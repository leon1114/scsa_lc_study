// 같은 코드 다시 돌렸는데
// Runtime: 2 ms, faster than 80.17% of C online submissions for Search in Rotated Sorted Array.
// Memory Usage: 6 MB, less than 74.14% of C online submissions for Search in Rotated Sorted Array.

// 호에에에에에에엥?? 이왜진...??
// Runtime: 13 ms, faster than 6.28% of C online submissions for Search in Rotated Sorted Array.
// Memory Usage: 6 MB, less than 48.03% of C online submissions for Search in Rotated Sorted Array.

int search(int* nums, int numsSize, int target){
    int index = -1;
    int left = 0, right = numsSize - 1, tmp;
    if (nums[left] == target) {
        return left;
    } else if (nums[right] == target) {
        return right;
    }
    while(left < right) {
        if (nums[left] == target) {
            return left;
        } else if (nums[right] == target) {
            return right;
        } else if (nums[left] > nums[right]) {
            tmp = (left + right + 1) / 2;
            if (target == nums[tmp]) {
                return tmp;
            } else if (target < nums[left] && target > nums[right] || right == tmp) {
                return -1;
            } else if (target > nums[tmp] && target < nums[right]) {
                left = tmp + 1;
            } else if (target > nums[left] && target < nums[tmp]) {
                right = tmp;
            } else if (nums[left] < nums[tmp]) {
                left = tmp + 1;
            } else if (nums[right] > nums[tmp]) {
                right = tmp;
            }
        } else {
            tmp = (left + right + 1) / 2;
            if (target == nums[tmp]) {
                return tmp;
            } else if (target < nums[left] || target > nums[right] || right == tmp) {
                return -1;
            } else if (target < nums[tmp]) {
                right = tmp;
            } else {
                left = tmp + 1;
            }
        }
    }
    return index;
}


// // Runtime: 4 ms, faster than 61.29% of C online submissions for Search in Rotated Sorted Array.
// // Memory Usage: 5.9 MB, less than 97.57% of C online submissions for Search in Rotated Sorted Array.
// // 이왜진? 이왜진?? 이게~ 왜~ 쥔쫘~~~~?

// int search(int* nums, int numsSize, int target){
//     int index = -1;
//     for(int i = 0; i < numsSize; i++) {
//         if (nums[i] == target) index = i;
//     }
//     return index;
// }
