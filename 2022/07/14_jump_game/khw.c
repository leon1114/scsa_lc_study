/*
Runtime: 128 ms, faster than 35.06% of C online submissions for Jump Game.
Memory Usage: 8.5 MB, less than 28.29% of C online submissions for Jump Game.

DFS로 처음에 구현했는데 	Time Limit Exceeded 떠서 O(N)으로 다시 구현함.
DFS는 시간 복잡도가 어떻게 되는 거임?
*/

bool canJump(int* nums, int numsSize){

    int tempSum=0;
    int max = 0;
    for(int i = 0; i<= max; i++)
    {
        max = max > i+nums[i] ? max : i+nums[i];
        if(max >= numsSize-1) return true;
    }

    return false;
}


// bool DFS(int * nums, int numsSize, int idx)
// {   
//     bool re;
//     if(idx == numsSize-1 || idx+nums[idx] >= numsSize-1){
//         return true;
//     } else if (idx >= numsSize){
//         return false;
//     }
//     for(int i = nums[idx]; i>0; i--)
//     {
//         re = DFS(nums, numsSize, idx+i);
//         if(re == true) return true;
//     }
//     return re;
// }
