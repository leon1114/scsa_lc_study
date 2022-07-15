// Runtime: 4 ms, faster than 26.25% of C online submissions for Spiral Matrix.
// Memory Usage: 5.8 MB, less than 64.17% of C online submissions for Spiral Matrix.
// 머고 왤케 느리누
// Runtime: 0 ms, faster than 100.00% of C online submissions for Spiral Matrix.
// Memory Usage: 5.7 MB, less than 64.17% of C online submissions for Spiral Matrix.
// 두번 더 돌리면 빨라짐~

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize){
    *returnSize = matrixSize * (*matrixColSize);
    int *ret = (int*)malloc(sizeof(int) * (*returnSize));
    int check[10][10] = {0};
    int cnt = 0, col = 0, row = 0, n_col, n_row;
    int dir_arr[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int dir = 0, invalid_dir;
    
    while(cnt < *returnSize) {
        ret[cnt++] = matrix[row][col];
        check[row][col] = -1;
        invalid_dir = 1;
        while(invalid_dir < 5) {
            // move once
            n_row = row + dir_arr[dir][0]; n_col = col + dir_arr[dir][1];
            
            // out of bound || have been there => change direction
            if (n_row < 0 || n_col < 0 || n_row >= matrixSize || n_col >= *matrixColSize ||
               check[n_row][n_col] == -1) {
                dir = (dir+1) % 4;
                invalid_dir++;
            } else break;
        }
        if (invalid_dir == 5) break;
            
        col = n_col; row = n_row;
    }
    return ret;
}

// [0, 0...3] , [0..2,3], [2, 3..0], [2..1, 0], [1, 0..2]
