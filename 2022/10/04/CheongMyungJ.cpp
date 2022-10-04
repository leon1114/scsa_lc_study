//Runtime: 104 ms, faster than 80.65% of C++ online submissions for Coin Change.
//Memory Usage: 10.1 MB, less than 95.45% of C++ online submissions for Coin Change.
//amount 까지 숫자 하나씩 증가시키면서 dp배열 채워서 품

class Solution {
public:
    
    int coinChange(vector<int>& coins, int amount) {
        int dp[10001]{};
        for (int i = 1; i < 10001; i++) dp[i] = 10001;
        sort(coins.begin(), coins.end());
        
        for (int i = 1; i <= amount; i++){
            for (int j = coins.size() - 1; j >= 0; j--){
                if (i - coins[j] < 0) continue;
                if (dp[i - coins[j]] < 10001 && dp[i] > dp[i - coins[j]] + 1) {
                    dp[i] = dp[i - coins[j]] + 1;
                }
            }
        }
        if (dp[amount] == 10001) return -1;
        return dp[amount];
    }
};
