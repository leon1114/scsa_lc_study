// 이거도 O(n)으로 쳐주나?
// Runtime: 174 ms, faster than 63.87% of C online submissions for First Missing Positive.
// Memory Usage: 29.9 MB, less than 93.43% of C online submissions for First Missing Positive.

int firstMissingPositive(int* nums, int numsSize){
    int ret = 1;
    int map[500005] = {0, };
    for(int i = 0; i < numsSize; i++) {
        if (nums[i] == ret) {
            while(map[++ret]);
        } else if (nums[i] <= 500000 && nums[i] > 0) {
            map[nums[i]] = 1;
        }
    }
    return ret;
}
