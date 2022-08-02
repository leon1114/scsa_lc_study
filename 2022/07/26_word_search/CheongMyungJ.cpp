//Runtime: 233 ms, faster than 95.61% of C++ online submissions for Word Search.
//memory Usage: 8 MB, less than 73.84% of C++ online submissions for Word Search.
//재귀로 풀면 간단.
//가지치기 요소들을 찾아보자.
//1. word의 첫 문자와 동일한 부분부터 시작한다.
//2. 4방향중 안가본 방향만 간다(check)
//3. 다음 문자랑 동일한 문자인 곳만 간다.
// 또있을까?
  
class Solution {
private:
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
    int check[6][6] = {{0,},};
public:
    bool recursive(vector<vector<char>>& board,
                   int x, int y, int depth, string& word){
        if (depth == word.length())
            return true;
        
        for (int i = 0; i < 4; i++){
            int nx = x + dx[i]; 
            int ny = y + dy[i];
            if (nx < 0 || nx >= board[0].size() || ny < 0 || ny >= board.size()) continue;
            if (check[ny][nx] == 1) continue;
            if (board[ny][nx] != word[depth]) continue;
            check[ny][nx] = 1;
            if (recursive(board, nx, ny, depth+1, word) == true)
                return true;
            check[ny][nx] = 0;
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        memset(check, 0, sizeof(int) * 36);
        for (int i = 0; i < board.size(); i++){
            for (int j = 0; j < board[0].size(); j++){
                if (board[i][j] == word[0]){
                    check[i][j] = 1;
                    if (recursive(board, j, i, 1, word) == true)
                        return true;
                    check[i][j] = 0;
                }
            }
        }
        return false;
    }
};
