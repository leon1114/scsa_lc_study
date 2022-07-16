//Runtime: 96 ms, faster than 62.26% of C++ online submissions for Jump Game.
//Memory Usage: 48.4 MB, less than 43.15% of C++ online submissions for Jump Game.
//가다가 0을 만나면 이전 숫자들중에서 이걸 뛰어넘을 수 있는지 파악해야함.
//이전 숫자들 중 가장 큰걸 하나 저장하는데 이건 한칸 지나갈때마다 1씩 감소. 현재 위치의 숫자가 그것보다 크면 업데이트
//만약 0을 만나더라도 이게 마지막 인덱스면 true임
  


class Solution {
public:
    bool canJump(vector<int>& nums) {
        int left_power = nums[0];
        if (left_power == 0 && nums.size() > 1) return false;
        for (int i = 1; i < nums.size(); i++){
            left_power--;
            if (nums[i] == 0 && left_power == 0 && i != nums.size() - 1)
                return false;
            if (left_power < nums[i])
                left_power = nums[i];
        }
        return true;
    }
};
