//Runtime: 13 ms, faster than 87.99% of C++ online submissions for Surrounded Regions.
//Memory Usage: 10.2 MB, less than 40.31% of C++ online submissions for Surrounded Regions.
//오랜만의 bfs
//모서리에 있는 0에서 출발해서 인접한 0들을 체크 싹 해준다음
//모든 지점 보면서 체크 안된 'O'가 있다면, 그놈은 둘러쌓인놈.

class Solution {
    int dx[4] = { 0,0,-1,1 };
    int dy[4] = { 1,-1,0,0 };
    struct st {
        int x;
        int y;
        st(int x, int y) :x(x), y(y) {}
    };
    int max_x;
    int max_y;
public:
    void move(int& x, int& y, int& dir_flag) {
        if (dir_flag == 0) {
            if (x < max_x - 1)
                x++;
            else {
                dir_flag = 1;
                y++;
            }
        }
        else if (dir_flag == 1) {
            if (y < max_y - 1)
                y++;
            else {
                dir_flag = 2;
                x--;
            }
        }
        else if (dir_flag == 2) {
            if (x > 0)
                x--;
            else {
                dir_flag = 3;
                y--;
            }
        }
        else {
            y--;
        }
    }
    void bfs(int& x, int& y, vector<vector<char>>& board) {
        queue<st> q;
        q.push(st(x, y));
        board[y][x] = '1';
        while (q.size()) {
            st s = q.front();
            q.pop();
            
            for (int i = 0; i < 4; i++) {
                int nx = s.x + dx[i];
                int ny = s.y + dy[i];
                if (nx < 0 || nx >= max_x || ny < 0 || ny >= max_y) continue;
                if (board[ny][nx] != 'O') continue;
                board[ny][nx] = '1';
                q.push(st(nx, ny));
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        max_x = board[0].size();
        max_y = board.size();
        if (max_x <= 2 || max_y <= 2) return;
        int edge_cnt = 0;
        int max_cnt = max_y * 2 + max_x * 2 - 4;
        int x = 0;
        int y = 0;
        int dir_flag = 0;

        while (edge_cnt < max_cnt) {
            if (board[y][x] == 'O')
                bfs(x, y, board);

            move(x, y, dir_flag);
            edge_cnt++;
        }
        for (int i = 0; i < max_y; i++) {
            for (int j = 0; j < max_x; j++) {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                else if (board[i][j] == '1')
                    board[i][j] = 'O';
            }
        }
    }
};
