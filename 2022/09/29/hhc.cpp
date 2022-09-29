// Runtime: 476 ms, faster than 36.69% of C++ online submissions for Longest Increasing Subsequence.
// Memory Usage: 10.3 MB, less than 97.93% of C++ online submissions for Longest Increasing Subsequence.

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int dp[2505] = {1, };
        int max = 1;
        for (int i = 1; i < nums.size(); i++) {
            dp[i] = 1;
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j] && dp[i] < dp[j] + 1) dp[i] = dp[j] + 1;
            }
            if (dp[i] > max) max = dp[i];
        }
        return max;
    }
};
