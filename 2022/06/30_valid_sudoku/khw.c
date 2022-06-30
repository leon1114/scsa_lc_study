/*
Runtime: 22 ms, faster than 19.15% of C online submissions for Valid Sudoku.
Memory Usage: 5.9 MB, less than 49.37% of C online submissions for Valid Sudoku.
주어진 배열 가지고 풀수 있는 스도쿠인줄 판별하는 줄 알고 삽질함...
기존에 스도쿠 푸는거 가지고 살짝 고쳐서 작성한 코드라 쓸데없이 변수 가져다쓰고 좀 지저분함
*/
bool checkColumn(char ** board, int rowIndex, int columnIndex, int num)
{
    int count =0;
    for(int i =0;i<9;i++)
    {
        if( board[rowIndex][i]==num+'0')
        {
            count++;
        }
    }
    return count>1? false:true;
}
bool checkRow(char ** board, int rowIndex, int columnIndex, int num)
{
    int count = 0;
    for(int i =0;i<9;i++)
    {
        if( board[i][columnIndex]==num+'0')
        {
            count++;
        }
    }
    return count>1? false:true;
}
bool checkBlock(char ** board, int rowIndex, int columnIndex, int num)
{    
    int count = 0;
    
    for(int i = (rowIndex/3)*3; i<((rowIndex/3)+1)*3 ;i++)
    {
        for(int j = (columnIndex/3)*3 ; j < ((columnIndex/3)+1)*3; j++)
        {
            if( board[i][j]==num+'0')
            {
                count++;
            }
        }
    }
    return count>1? false:true;
}

bool isValidSudoku(char** board, int boardSize, int* boardColSize){
    bool re = true;

    for(int i =0; i<9; i++)
    {
        for(int j =0; j<9; j++)
        {
            if(board[i][j]=='.') continue;
            else
            {   
                re = checkColumn(board, i, j, board[i][j]-'0');
                if(re == false)return false;
                re = checkRow(board, i, j, board[i][j]-'0');
                if(re == false)return false;
                re = checkBlock(board, i, j, board[i][j]-'0');
                if(re == false)return false;
            }
        }        
    }

    return re;
}
