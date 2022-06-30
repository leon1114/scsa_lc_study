// Runtime: 7 ms, faster than 97.31% of C online submissions for Valid Sudoku.
// Memory Usage: 5.7 MB, less than 97.94% of C online submissions for Valid Sudoku.


void reset_map10(int * map) {
    for(int i = 1; i <= 9; i++) {
        map[i] = 0;
    }
}

bool isValidSudoku(char** board, int boardSize, int* boardColSize){
    bool valid = true;
    int map[10] = {0, };
    int box_start[9][2] = {{0,0}, {0,3}, {0,6},
                           {3,0}, {3,3}, {3,6},
                           {6,0}, {6,3}, {6,6}};
    int box_elements[9][2] = {{0,0}, {0,1}, {0,2},
                              {1,0}, {1,1}, {1,2},
                              {2,0}, {2,1}, {2,2}};
    
    // row check
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            if (board[i][j] == '.') continue;
            map[board[i][j] - '0']++;
            if (map[board[i][j] - '0'] >= 2) return false;
        }
        reset_map10(map);
    }
    
    // col check
    for(int j = 0; j < 9; j++) {
        for(int i = 0; i < 9; i++) {
            if (board[i][j] == '.') continue;
            map[board[i][j] - '0']++;
            if (map[board[i][j] - '0'] >= 2) return false;
        }
        reset_map10(map);
    }
    
    // box check
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            char tmp = board[box_start[i][0] + box_elements[j][0]][box_start[i][1] + box_elements[j][1]];
            if (tmp == '.') continue;
            map[tmp - '0']++;
            if (map[tmp - '0'] >= 2) return false;
        }
        reset_map10(map);
    }
    
    return valid;
}
