//Runtime: 177 ms, faster than 63.72% of C++ online submissions for Longest Increasing Subsequence.
//Memory Usage: 10.3 MB, less than 97.93% of C++ online submissions for Longest Increasing Subsequence.
//O(n^2)이라서 비효율적이네. flow up에 nlogn 해보라는데 딱 떠오르진 않음..
//dp로 했는데 k번째 숫자는 k-1, k-2, ... 1 번 연속된 놈들(있다고 가정)의 가장 마지막 숫자 대비해서 커야 이어짐


class Solution {
    const int INF = 0x7fffffff;
public:
	int lengthOfLIS(vector<int>& nums) {
		int ret = 0;
		int dp[2501]{};
		for (int i = 0; i < 2501; i++) dp[i] = INF;
		dp[0] = -10001;
		for (int i = 0; i < nums.size(); i++) {
			for (int j = i; j >= 0; j--) {
				if (dp[j] < nums[i] && dp[j + 1] > nums[i]) {
					dp[j + 1] = nums[i];
					if (ret < j + 1)
						ret = j + 1;
				}	
			}
		}
		return ret;
	}
};
