// Runtime: 157 ms, faster than 73.68% of C online submissions for Word Search.
// Memory Usage: 5.5 MB, less than 71.43% of C online submissions for Word Search.
// 백트래킹으로 해보자전거
bool search_word(char** board, int* m, int* n, char* word, int i, int j) {
    // 탈출족건 board벗어남 / word일치 / word틀림 
    if (i >= *m || j >= *n || i < 0 || j < 0) return false;
    if (*word == '\0') return true;
    if (board[i][j] != *word) return false;
    
    char tmp = board[i][j];
    board[i][j] = '\0';
    if (search_word(board, m, n, word+1, i+1, j)) return true;
    if (search_word(board, m, n, word+1, i, j+1)) return true;
    if (search_word(board, m, n, word+1, i-1, j)) return true;
    if (search_word(board, m, n, word+1, i, j-1)) return true;
    if (word[1] == '\0') return true;
    board[i][j] = tmp;
    return false;
}

bool exist(char** board, int boardSize, int* boardColSize, char * word){
    for(int i = 0; i < boardSize; i++) {
        for(int j = 0; j < *boardColSize; j++) {
            if (board[i][j] != word[0]) continue;
            if (search_word(board, &boardSize, boardColSize, word, i, j)) return true;
        }
    }
    return false;
}
