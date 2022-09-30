//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Game of Life.
//memory Usage: 6.9 MB, less than 84.57% of C++ online submissions for Game of Life.
//추가 공간 안쓰고 풀도록 해봄
//변할 값을 두번째 비트에 쓰는 전략. 첫번째 비트만 읽어서 다음 상태를 두번째 비트에 씀 (return 0 or 2)
//마지막 한번 더 돌면서 오른쪽으로 시프트 1

class Solution {
public:
    int checkNeighbors(vector<vector<int>>& board, int i, int j){
        int sum = 0;
        if (i - 1 >= 0 && j - 1 >= 0) sum += (board[i-1][j-1] & 0x1);
        if (i - 1 >= 0) sum += (board[i-1][j] & 0x1);
        if (i - 1 >= 0 && j + 1 < board[0].size()) sum += (board[i-1][j+1] & 0x1);
        if (j - 1 >= 0) sum += board[i][j-1] & 0x1;
        if (j + 1 < board[0].size()) sum += (board[i][j+1] & 0x1);
        if (i + 1 < board.size() && j - 1 >= 0) sum += (board[i+1][j-1] & 0x1);
        if (i + 1 < board.size()) sum += (board[i+1][j] & 0x1);
        if (i + 1 < board.size() && j + 1 < board[0].size()) sum += (board[i+1][j+1] & 0x1);
        if (board[i][j] == 1){
            if (sum < 2) return 0;
            else if (sum > 3) return 0;
            else return 2;
        }
        else{
            if (sum == 3) return 2;
            else return 0;
        }
    }
    void gameOfLife(vector<vector<int>>& board) {
        for (int i = 0; i < board.size(); i++){
            for (int j = 0; j < board[0].size(); j++){
                board[i][j] += checkNeighbors(board, i, j);
            }
        }
        for (int i = 0; i < board.size(); i++){
            for (int j = 0; j < board[0].size(); j++){
                board[i][j] = board[i][j] >> 1;
            }
        }
    }
};
