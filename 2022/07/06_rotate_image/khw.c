
/*

Runtime: 7 ms, faster than 38.26% of C online submissions for Rotate Image.
Memory Usage: 6.5 MB, less than 27.42% of C online submissions for Rotate Image.

기존 로직에서 2D 배열 안넣고 풀수 있게 수정함
이렇게 하는건 됨??

*/


void rotate(int** matrix, int matrixSize, int* matrixColSize){

    if(matrixSize%2==1)
    {
        for (int i =0; i<(matrixSize/2)+1; i++)
        {
            for (int j = 0; j < (matrixSize/2); j++)
            {
                int temp_i, temp_j, tmp;
                int temp[4];
                temp_i = i;
                temp_j = j;

                for(int k = 0; k < 4 ; k++)
                {
                    temp[k] = matrix[temp_i][temp_j];
                    tmp = temp_i;
                    temp_i = temp_j;
                    temp_j = (matrixSize-1) - tmp;
                }
                temp_i = j;
                temp_j = (matrixSize-1) - i;
                for(int k = 0; k < 4 ; k++)
                {
                    matrix[temp_i][temp_j]=temp[k];
                    tmp = temp_i;
                    temp_i = temp_j;
                    temp_j = (matrixSize-1) - tmp;
                }
            }
        }
    }
    else {
        for (int i =0; i<matrixSize/2; i++)
        {
            for (int j = 0; j < matrixSize/2; j++)
            {
                int temp_i, temp_j, tmp;
                int temp[4];
                temp_i = i;
                temp_j = j;

                for(int k = 0; k < 4 ; k++)
                {
                    temp[k] = matrix[temp_i][temp_j];
                    tmp = temp_i;
                    temp_i = temp_j;
                    temp_j = (matrixSize-1) - tmp;
                }
                temp_i = j;
                temp_j = (matrixSize-1) - i;
                for(int k = 0; k < 4 ; k++)
                {
                    matrix[temp_i][temp_j]=temp[k];
                    tmp = temp_i;
                    temp_i = temp_j;
                    temp_j = (matrixSize-1) - tmp;
                }
            }
        }
    }
}

