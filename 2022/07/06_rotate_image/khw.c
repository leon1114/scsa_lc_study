/*

Runtime: 4 ms, faster than 71.01% of C online submissions for Rotate Image.
Memory Usage: 6.2 MB, less than 94.67% of C online submissions for Rotate Image.

*/


void rotate(int** matrix, int matrixSize, int* matrixColSize){

    int temp[matrixSize][matrixSize];

    for (int i =0; i<matrixSize; i++)
    {
        for (int j = 0; j < matrixSize; j++)
        {
            temp[j][ (matrixSize-1) -i] = matrix[i][j];
        }
    }
    for (int i = 0; i < matrixSize; i++)
    {
        for (int j = 0; j < matrixSize; j++)
        {
            matrix[i][j] = temp[i][j];
        }
    }
}
