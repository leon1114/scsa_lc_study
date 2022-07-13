// Runtime: 96 ms, faster than 61.79% of C online submissions for Jump Game.
// Memory Usage: 8.4 MB, less than 51.14% of C online submissions for Jump Game.

bool canJump(int* nums, int numsSize){
    int idx = 0;
    int prv_idx;
    
    while (true) {
        if (idx >= numsSize - 1) return true;
        if (nums[idx] == 0) {
            int i;
            for(i = idx - 1; i >= 0; i--) {
                if (i + nums[i] > idx) {
                    idx = i + nums[i];
                    break;
                }
            }
            if (idx >= numsSize - 1) return true;
            if (i < 0) return false;
        }
        prv_idx = idx;
        idx += nums[idx];
    }
    return false;
}
