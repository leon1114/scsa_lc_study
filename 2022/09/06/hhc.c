// Runtime: 2 ms, faster than 53.38% of C online submissions for House Robber.
// Memory Usage: 5.8 MB, less than 79.50% of C online submissions for House Robber.

int max(int x, int y){
    return x * (x >= y) + y * (y > x);
}

int rob(int* nums, int numsSize){
    if (numsSize == 0) {return 0;}
    if (numsSize == 1) {return nums[0];}
    if (numsSize == 2) {return max(nums[0], nums[1]);}
    int *dp = malloc(numsSize * sizeof(int));
    dp[0] = nums[0];
    dp[1] = nums[1];
    for (int i = 2; i < numsSize; i++) {
        dp[i] = max(max(nums[i] + dp[i-2], dp[i-1]), 
                    nums[i] + dp[i-1] - nums[i-1]);
    }
    return dp[numsSize-1];
}
