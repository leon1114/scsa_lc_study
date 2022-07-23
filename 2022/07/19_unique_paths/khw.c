/*
Runtime: 0 ms, faster than 100.00% of C online submissions for Unique Paths.
Memory Usage: 5.4 MB, less than 82.66% of C online submissions for Unique Paths.
DP 문제라서 DP로 풀었음
*/


int uniquePaths(int m, int n){

    int dp[m][n];
    
    for(int i =0; i< m ; i++) dp[i][0] = 1;
    for (int j = 0; j < n; j++) dp[0][j] = 1;
    for(int i =1; i< m ; i++)
    {
        for (int j = 1; j < n; j++)
        {
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }
    return dp[m-1][n-1];
}
