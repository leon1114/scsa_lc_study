/*
Runtime: 330 ms, faster than 13.53% of C online submissions for Word Search.
Memory Usage: 5.8 MB, less than 42.11% of C online submissions for Word Search.

첨에 Queue로 BFS로 풀려다가 갔던곳 다시 못가게 하는게 좀 애매해서
문장 시작지점 찾아서 상하좌우 찾아가는 재귀함수 짜서 풀었음...
follow Up에 뭐 더 큰 보드로 빠르게 해보라는데 뭘 어쩌라는건지 감이 안오네
*/

#define MAX_N 100


typedef struct word{
    int x;
    int y;
    char w;
    int wIdx;
}Word;

Word queue[MAX_N];

int check[10][10];

bool recursion(char** board, int boardSize, int* boardColSize, char * word, Word temp)
{
    if(word[temp.wIdx+1]== '\0') return true;
    Word next;
    int dir[4][2] ={ {1,0}, {-1,0}, {0,1}, {0,-1} };
    for (size_t i = 0; i < 4; i++)
    {
        next.x  = temp.x+dir[i][0];
        next.y  = temp.y+dir[i][1];
        if(next.x < 0 || next.x >= boardSize || next.y < 0 || next.y >= *boardColSize) continue;
        if(check[next.x][next.y]==1) continue;
        next.w = board[next.x][next.y];
        next.wIdx = temp.wIdx+1;

        if(next.w == word[temp.wIdx+1]){
            if(word[next.wIdx+1]== '\0') return true;
            check[next.x][next.y] = 1;
            if(recursion(board, boardSize, boardColSize, word, next))return true;
            check[next.x][next.y] = 0;
        }
    }
    return false;
}

bool exist(char** board, int boardSize, int* boardColSize, char * word){
    
    memset(check, 0, sizeof(check));
    int wordLen = strlen(word);
    //첫문자를 맵 전체에서 찾아서 Queue에 넣는다.
    
    Word temp;
    for (size_t i = 0; i < boardSize; i++)
    {
        for (size_t j = 0; j < *boardColSize; j++)
        {
            if(board[i][j]== word[0]){
                temp.wIdx = 0;
                temp.w = board[i][j];
                temp.x = i;
                temp.y = j;
                check[i][j]=1;
                if(recursion(board, boardSize, boardColSize, word, temp))return true;
                check[i][j]=0;
            }
        }
    }
    return false;
}
