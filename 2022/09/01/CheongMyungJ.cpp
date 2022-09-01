//Runtime: 6 ms, faster than 23.53% of C++ online submissions for Factorial Trailing Zeroes.
//Memory Usage: 6 MB, less than 29.88% of C++ online submissions for Factorial Trailing Zeroes.
//dp로 간단하게 해결~

class Solution {
public:
    int trailingZeroes(int n) {
        int dp[10001]{};
        for (int i = 1; i <= n; i++){
            int count = 0;
            int num = i;
            while (1){
                if (num % 5 == 0){
                    num /= 5;
                    count++;
                }
                else break;
            }
            dp[i] = dp[i - 1] + count;
        }
        return dp[n];
    }
};
