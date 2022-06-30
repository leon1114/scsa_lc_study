#include <stdio.h>
#include <stdbool.h>

// Runtime: 43 ms, faster than 5.38% of C online submissions for Valid Sudoku.
// Memory Usage: 5.9 MB, less than 49.37% of C online submissions for Valid Sudoku.

// 그냥 구현

#define MAX_NUM 9
#define MAX_HASH MAX_NUM + 3
#define MARKED 1
#define NOT_MARKED 0

int hash_tb[MAX_HASH];

void init_hash_tb(void) 
{
    int i;
    for (i = 0; i < MAX_HASH; i++) {
            hash_tb[i] = NOT_MARKED;
    }
}

bool checkRow(char **board)
{
    int i, j;
    for (i = 0; i < MAX_NUM; i++) {
        init_hash_tb();
        for (j = 0; j < MAX_NUM; j++) {
            printf("check Row : board[%d][%d] = %c\n", i, j, board[i][j]);
            if (board[i][j] == '.') continue;
            if (hash_tb[board[i][j] - '0'] == MARKED) return false;
            else hash_tb[board[i][j] - '0'] = MARKED;
       }
    }
    return true;
}

bool checkColumn(char **board)
{
    int i, j;
    for (i = 0; i < MAX_NUM; i++) {
        init_hash_tb();
        for (j = 0; j < MAX_NUM; j++) {
            printf("check Col : board[%d][%d] = %c\n", j, i, board[j][i]);
            if (board[j][i] == '.') continue;
            if (hash_tb[board[j][i] - '0'] == MARKED) return false;
            else hash_tb[board[j][i] - '0'] = MARKED;
        }
    }
    return true;
}

bool checkSubBox(char **board) {
    int i, j, row, col;
    for (i = 0; i < MAX_NUM; i+=3) { // 3번돔
        for (j = 0; j < MAX_NUM; j+=3) { // 3번돔
            init_hash_tb();
            for (row = i; row < i + 3; row++) { // 3번돔 
                for (col = j; col < j + 3; col++) { // 3번돔 
                    printf("check SubBox : board[%d][%d] = %c\n", row, col, board[row][col]);
                    if (board[row][col] == '.') continue;
                    if (hash_tb[board[row][col] - '0'] == MARKED) return false;
                    else hash_tb[board[row][col] - '0'] = MARKED;
                }
            }
        }
    }
    return true;
}

bool isValidSudoku(char **board, int boardSize, int *boardColSize)
{
    *boardColSize = 9;
    return checkRow(board) && checkColumn(board) && checkSubBox(board);
}
