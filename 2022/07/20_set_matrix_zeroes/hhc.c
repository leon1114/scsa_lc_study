// Runtime: 47 ms, faster than 95.08% of C online submissions for Set Matrix Zeroes.
// Memory Usage: 11.1 MB, less than 22.95% of C online submissions for Set Matrix Zeroes.

void setZeroes(int** matrix, int matrixSize, int* matrixColSize){
    int chk_col[201] = {0, }, chk_row[201] = {0, };
    // m = matrixSize,  n = *matrixColSize
    int m = matrixSize, n = *matrixColSize;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == 0) {
                chk_col[i] = 1;
                chk_row[j] = 1;
            }
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (chk_col[i] || chk_row[j]) matrix[i][j] = 0;
        }
    }
}
