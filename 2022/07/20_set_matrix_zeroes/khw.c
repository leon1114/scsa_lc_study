/*
Runtime: 64 ms, faster than 51.91% of C online submissions for Set Matrix Zeroes.
Memory Usage: 10.9 MB, less than 66.12% of C online submissions for Set Matrix Zeroes.

첫번째 행과 열에 0이 있는지 체크하고
행렬 중간에 있는 0은 첫번째 행과 열에 0으로 표시해주고 그걸로 0으로 칠해 줌
단계가 좀 구구절절하니 코드가 좀 구질구질하긴 함....
*/



void setZeroes(int** matrix, int matrixSize, int* matrixColSize){

    bool checkFirstRow = false;
    bool checkFirstColumn = false;

    for (size_t i = 0; i < matrixSize; i++)
    {
        if(matrix[i][0]==0){
            checkFirstColumn=true;
        }
    }

    for (size_t j = 0; j < *matrixColSize; j++)
    {
        if(matrix[0][j]==0){
            checkFirstRow=true;
        }
    }
    
    for (size_t i = 1; i < matrixSize; i++)
    {
        for (size_t j = 1; j < *matrixColSize; j++)
        {
            if(matrix[i][j]==0)
            {
                matrix[0][j]=0;
                matrix[i][0]=0;
            }
        }        
    }
    
    for (size_t i = 1; i < matrixSize; i++)
    {
        if(matrix[i][0]==0)
        {
            for (size_t j = 1; j < *matrixColSize; j++)
            {
                matrix[i][j] = 0;
            }
        }
    }

    for (size_t j = 1; j < *matrixColSize; j++)
    {
        if(matrix[0][j]==0)
        {
            for (size_t i = 1; i < matrixSize; i++)
            {
                matrix[i][j] = 0;
            }
        }
    }

    if(checkFirstRow)
    {
        for (size_t j = 0; j < *matrixColSize; j++)
        {
            matrix[0][j]=0;
        }
    }

    if(checkFirstColumn)
    {
        for (size_t i = 0; i < matrixSize; i++)
        {
            matrix[i][0]=0;
        }
    }
}
