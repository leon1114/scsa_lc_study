// Runtime: 0 ms, faster than 100.00% of C online submissions for Unique Paths.
// Memory Usage: 5.6 MB, less than 63.84% of C online submissions for Unique Paths.

// starts at [0][0]
// try to move bottom-right corner [m-1][n-1]

int chk_grid[101][101];

void set_chk(int m, int n) {
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < m; j++) chk_grid[i][j] = -1;
    }
    for(int i = 0; i < m; i++) {chk_grid[i][0] = 1; chk_grid[0][i] = 1;}
}

int dfs(int m, int n) {
    // 탈출조건
    if (chk_grid[m-1][n-1] >= 0) return chk_grid[m-1][n-1];
    // come from top
    int from_t = m - 2 >= 0 ? dfs(m - 1, n) : 0;
    // come from left
    int from_l = n - 2 >= 0 ? dfs(m, n - 1) : 0;
    int ret = from_t + from_l;
    chk_grid[m-1][n-1] = ret;
    return ret;
}

int uniquePaths(int m, int n){
    set_chk(100, 100);
    int ret = dfs(m, n);
    return ret;
}
