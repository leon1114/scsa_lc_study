//Runtime: 33 ms, faster than 58.06% of C++ online submissions for Valid Sudoku.
//Memory Usage: 17.9 MB, less than 96.98% of C++ online submissions for Valid Sudoku.
//머리아프군... 3개의 bool배열로 체크.

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool horizon[9][9] = {{0,},};
        bool vertical[9][9] = {{0,},};
        bool square[9][9] = {{0,},};
        for (int i = 0; i < 9; i++){
            for (int j = 0; j < 9; j++){
                if (board[i][j] != '.'){
                    if (horizon[i][board[i][j] - '1'] == false)
                        horizon[i][board[i][j] - '1'] = true;
                    else
                        return false;    
                }
                if (board[j][i] != '.'){
                    if (vertical[i][board[j][i] - '1'] == false)
                        vertical[i][board[j][i] - '1'] = true;
                    else
                        return false;    
                }
                if (board[i/3*3 + j/3][i*3%9 + j%3] != '.'){
                    if (square[i][board[i/3*3 + j/3][i*3%9 + j%3] - '1'] == false)
                        square[i][board[i/3*3 + j/3][i*3%9 + j%3] - '1'] = true;
                    else
                        return false;    
                }
                
                
            }
        }
        return true;
        
    }
};
