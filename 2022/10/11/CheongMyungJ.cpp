//Runtime: 100 ms, faster than 69.38% of C++ online submissions for Increasing Triplet Subsequence.
//Memory Usage: 61.6 MB, less than 24.04% of C++ online submissions for Increasing Triplet Subsequence.
//nums를 뒤에서부터 돌면서 first에는 가장 큰 수를, second에는 자기보다 큰 놈이 있는게 보장된 숫자 중 가장 큰 놈을 담는다
//만약 second보다 작은 놈이 나타나면 true

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int first = 1<<31;   
        int second = 1<<31;
        for (int i = nums.size() - 1; i >= 0; i--){
            if (nums[i] > first){
                first = nums[i];
            }
            else if (nums[i] < first){
                if (nums[i] > second){
                    second = nums[i];
                }
                else if (nums[i] < second) {
                    return true;
                }
            }
        }
        return false;
    }
};
