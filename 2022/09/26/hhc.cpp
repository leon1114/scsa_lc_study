// Runtime: 102 ms, faster than 89.56% of C++ online submissions for Perfect Squares.
// Memory Usage: 6 MB, less than 94.31% of C++ online submissions for Perfect Squares.

#define INF 0x3f3f3f
class Solution {
public:
    int numSquares(int n) {
        int dp[n + 1];
        memset(dp, INF, sizeof(dp)); // dp INF로 set
        dp[0] = 0;
        for(int i = 1; i <= n; i++) { // i 1:n까지 가면서
            for(int j = 1; j * j <= i; j++) { // perfect square 늘려가며
                dp[i] = min(dp[i], dp[i - j * j] + 1); // dp 췤
            }
        }
        return dp[n];
    }
};
