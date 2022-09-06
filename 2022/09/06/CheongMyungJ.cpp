//Runtime: 40 ms, faster than 85.37% of C++ online submissions for Number of Islands.
//Memory Usage: 12.2 MB, less than 96.71% of C++ online submissions for Number of Islands.
//bfs로도 풀어봤는데 단순 0으로 치환하고 끝나는 문제( 찾는 문제가 아닌)는 dfs가 더 빠른듯( 약 2배)

class Solution {
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {1, -1, 0, 0};
public:
    
    void searchMap(vector<vector<char>>& grid, int y, int x){
        for (int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= grid[0].size() || ny < 0 || ny >= grid.size()) continue;
            if (grid[ny][nx] == '0') continue;
            grid[ny][nx] = '0';
            searchMap(grid, ny, nx);
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int sol = 0;
        for (int i = 0; i < grid.size(); i++){
            for (int j = 0; j < grid[0].size(); j++){
                if (grid[i][j] == '1'){
                    searchMap(grid, i, j);
                    sol++;
                }
            }
        }
        return sol;
    }
};
