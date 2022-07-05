// Runtime: 4 ms, faster than 70.25% of C online submissions for Rotate Image.
// Memory Usage: 6.2 MB, less than 94.52% of C online submissions for Rotate Image.

void rotate(int** matrix, int matrixSize, int* matrixColSize){
    int rot_val, col, row, tmp, next_val;
    
    // 이중포문으로 돌리기 시작점 정하기
    // 각각 4번씩 돌릴 거라 두번 돌리지 않도록 유니크한 돌림지점을 찾아야함. 아래 예시의 R 위치를 설정
    // 5x5
    // R R R O O
    // R R R O O
    // O O O O O
    // O O O O O
    // O O O O O
    for (int col_rot = 0; col_rot < (matrixSize + 1) / 2; col_rot++) {
        for (int row_rot = 0; row_rot < matrixSize / 2; row_rot++) {
            col = col_rot; row = row_rot;
            rot_val = matrix[row][col];
            
            // 4번 돌려돌려
            // 청명 풀이처럼 loop 없이 걍 4번 하는게 좀 더 빠를 듯?
            for(int i = 0; i < 4; i++) {
                tmp = col;  col = matrixSize - 1 - row; row = tmp;
                next_val = matrix[row][col];
                matrix[row][col] = rot_val;
                rot_val = next_val;
            }
        }
    }
}

// 3x3
// 00 -> 02 -> 22 -> 20 -> 00
// 01 -> 12 -> 21 -> 10 -> 01

// 4x4
// 00 03 33 30 00
// 01 13 32 20 01
// 02 32 13 10 02
// 11 12 22 21 11
