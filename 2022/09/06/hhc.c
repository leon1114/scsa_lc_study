// Runtime: 34 ms, faster than 77.97% of C online submissions for Number of Islands.
// Memory Usage: 9.2 MB, less than 45.82% of C online submissions for Number of Islands.
int dir[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
int queue[90005][2] = {0, };

int numIslands(char** grid, int gridSize, int* gridColSize)
{
    // dfs + bfs approach
    int res = 0;
    int m = gridSize, n = *gridColSize;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == '1') {
                grid[i][j]++;
                res++;
                
                // bfs block
                int q_s = 0, q_e = 0;
                queue[q_e][0] = i;
                queue[q_e++][1] = j;
                while(q_s < q_e) {
                    int ii = queue[q_s][0], jj = queue[q_s++][1];
                    for (int k = 0; k < 4; k++) {
                        int ni = ii + dir[k][0];
                        int nj = jj + dir[k][1];
                        if (ni < 0 || ni >= m || nj < 0 || nj >= n) continue;
                        if (grid[ni][nj] == '1') {
                            grid[ni][nj]++;
                            queue[q_e][0] = ni;
                            queue[q_e++][1] = nj;
                        }
                    }
                }
                ////
                
            }
        }
    }
    return res;
}
