/*
Runtime: 121 ms, faster than 88.79% of C online submissions for Maximum Subarray.
Memory Usage: 12.2 MB, less than 75.40% of C online submissions for Maximum Subarray.
*/

int maxSubArray(int* nums, int numsSize){

    int max = nums[0];
    int tempSum = 0;
    for(int i = 0; i< numsSize; i++)
    {
        if(tempSum < 0) tempSum = 0;
        tempSum += nums[i];
        max = max > tempSum ? max : tempSum;
    }
    return max;
}




// int main()
// {
//     /*
//     [-2,1,-3,4,-1,2,1,-5,4]
//     [1]
//     [5,4,-1,7,8]
//     [-1]
//     [-2,1,-5]
//     [-2,-1]
//     [-2,-1,-2]
//     [9,0,-2,-2,-3,-4,0,1,-4,5,-8,7,-3,7,-6,-4,-7,-8]
//     */
//     int nums[9] = {-2,1,-3,4,-1,2,1,-5,4};
// //    int nums[18] ={9,0,-2,-2,-3,-4,0,1,-4,5,-8,7,-3,7,-6,-4,-7,-8};
//     int re = maxSubArray(nums, sizeof(nums)/sizeof(int));


//     return 0;
// }
