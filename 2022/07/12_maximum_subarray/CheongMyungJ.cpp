//Runtime: 166 ms, faster than 50.27% of C++ online submissions for Maximum Subarray.
//Memory Usage: 67.8 MB, less than 53.45% of C++ online submissions for Maximum Subarray.
// 일단 음수면 걍 ret값 업데이트만 해주고(모두 음수일수도 있으니), 양수부터 시작하는게 원칙
// 양수부터 시작해서 쭉 가면서 숫자들 더하는데, 만약 계속 더하다가 더한값이 음수가 된다면 
// 더하기를 시작한부분부터 현재 위치까지는 이후에 숫자들과 연결하지 않는 것이 이득.
// 따라서 이 때 다시 양수 시작점을 찾는 과정을 반복.
// O(n) 방법.

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ret = -10001;
        int sub_sum = 0;
        for (int i = 0; i < nums.size(); i++){
            if (sub_sum == 0){ // 맨 처음이거나, sub_sum이 음수가 되어 다시 초기화 된 상태
                if (nums[i] >= 0){
                    sub_sum = nums[i];
                }
                if (ret < nums[i])
                    ret = nums[i];
            }
            else { // 양수 시작점에서부터 계속 진행중인 상태
                if (sub_sum + nums[i] <= 0) // 만약 이번위치까지의 sub_sum이 음수가 된다면 여기서 끊고 다음 양수를 찾아야함.
                    sub_sum = 0;
                else { // 이번위치까지 더해도 양수라면 계속 진행
                    sub_sum += nums[i];
                    if (ret < sub_sum)
                        ret = sub_sum;
                }
            }
        }
        return ret;
    }
};
