// Runtime: 96 ms, faster than 61.79% of C online submissions for Jump Game.
// Memory Usage: 8.4 MB, less than 51.14% of C online submissions for Jump Game.

bool canJump(int* nums, int numsSize){
    int idx = 0;
    while (true) {
        if (idx >= numsSize - 1) return true; // idx가 배열 끝 지나갔으면 true~
        if (nums[idx] == 0) { // 0을 만나면 거기서부터 앞으로 찾아가면서 현위치 짬프해서 지나가지나 확인~
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
        // 일단 최대 사정거리로 짬프
        idx += nums[idx];
    }
    return false;
}
