//Runtime: 0 ms, faster than 100.00% of C++ online submissions for House Robber.
//Memory Usage: 7.6 MB, less than 77.54% of C++ online submissions for House Robber.
//dp로 간단하게 해결~

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1)
            return nums[0];
        int dp[101]{};
        dp[0] = nums[0];
        dp[1] = max(dp[0], nums[1]);
        for (int i = 2; i < nums.size(); i++){
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        }
        return dp[nums.size() - 1];
    }
};
