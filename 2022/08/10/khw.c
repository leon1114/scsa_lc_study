/*
Runtime: 34 ms, faster than 86.21% of C online submissions for Surrounded Regions.
Memory Usage: 11.2 MB, less than 34.48% of C online submissions for Surrounded Regions.
*/


void checkCapture(char ** board, int boardSize, int boardColSize, int x, int y)
{
    if(x < 0 || x >= boardSize || y < 0 || y >= boardColSize || board[x][y] == 'X' || board[x][y]=='1')
        return;
    if(board[x][y] == 'O')
    {
        board[x][y] = '0';
        checkCapture(board, boardSize, boardColSize, x + 1, y);
        checkCapture(board, boardSize, boardColSize, x - 1, y);
        checkCapture(board, boardSize, boardColSize, x, y + 1);
        checkCapture(board, boardSize, boardColSize, x, y - 1);
    }    
}

void solve(char** board, int boardSize, int* boardColSize){
    //가장자리부터 연결된 O만 capture 안된 놈들
    //DFS로 타고 들어가서 연결된 애들만 0 로 표시해주고 나머지는 X로 바꿔줌
    for(int i=0; i<boardSize; i++)
    {
        if(board[i][0] == 'O')
            checkCapture(board, boardSize, *boardColSize, i, 0);
        if(board[i][(*boardColSize)-1] == 'O')
            checkCapture(board, boardSize, *boardColSize, i, (*boardColSize)-1);
    }
    for(int j=1; j<*boardColSize-1; j++)
    {
        if(board[0][j] == 'O')
            checkCapture(board, boardSize, *boardColSize, 0, j);
        if(board[boardSize-1][j] == 'O')
            checkCapture(board, boardSize, *boardColSize, boardSize-1, j);
    }
    for(int i=0; i<boardSize; i++)
        for(int j=0; j<*boardColSize; j++)
            if(board[i][j] == '0')
                board[i][j] = 'O';
            else board[i][j] = 'X';
    return board;        
}
