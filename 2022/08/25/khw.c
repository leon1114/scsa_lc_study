/*
Runtime: 8 ms, faster than 72.68% of C online submissions for Maximum Product Subarray.
Memory Usage: 6.7 MB, less than 26.34% of C online submissions for Maximum Product Subarray.

가장 큰 양의 수,
가장 작은 음의 수 값을 계속 갱신해가면서 최대 값 구함
*/


int getMin(int a, int b, int c)
{
    int min = a < b ? a : b;
    min = min < c ? min : c;
    return min;
}
int getMax(int a, int b, int c)
{
    int max = a > b ? a : b;
    max = max > c ? max : c;
    return max;
}

int maxProduct(int* nums, int numsSize){
    
    int max = INT_MIN;
    int maxPositive = 1, maxNegative = 1;
    for (int i = 0; i < numsSize; i++)
    {
        int temp = maxNegative;
        maxNegative = getMin(nums[i], maxNegative*nums[i], maxPositive*nums[i]);
        maxPositive = getMax(nums[i], temp*nums[i], maxPositive*nums[i]);
        max = max > maxPositive? max: maxPositive;
    }    
    return max;
}
