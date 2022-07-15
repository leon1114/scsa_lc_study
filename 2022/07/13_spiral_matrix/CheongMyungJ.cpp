//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Spiral Matrix.
//memory Usage: 6.9 MB, less than 72.05% of C++ online submissions for Spiral Matrix.
//슥사때로 돌아간것 같구만... 시계방향 돌면서 범위를 벗어나거나 기존에 왔던 길이면 시계방향 90도 턴~
  
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};
        int dir = 0;
        
        int x_len = matrix.size();
        int y_len = matrix[0].size();
        int total_len = x_len * y_len;
        
        vector<int> ret;
        int check[10][10] = {{0,},};
        int x = 0;
        int y = 0;
        for (int i = 0; i < total_len; i++){
            ret.push_back(matrix[x][y]);
            check[x][y] = 1;
            if (x + dx[dir] == -1 || x + dx[dir] == x_len || y + dy[dir] == -1 || y + dy[dir] == y_len
               || check[x + dx[dir]][y + dy[dir]] == 1){
                dir++;
                dir %= 4;
            }
            x += dx[dir];
            y += dy[dir];
        }
        return ret;
    }
};
