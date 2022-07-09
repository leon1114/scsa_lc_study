

/**
Runtime: 0 ms, faster than 100.00% of C online submissions for Spiral Matrix.
Memory Usage: 5.7 MB, less than 93.78% of C online submissions for Spiral Matrix.
걍 구현
 */

int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize){

    int mFullCnt = matrixSize * (*matrixColSize);
    int * re = (int*)malloc(sizeof(int)*mFullCnt);
    *returnSize = mFullCnt;

    int reCnt = 0;
    int i=0, j=0, c =0;
    int left =0, right = (*matrixColSize)-1 , top = 0, bottom = matrixSize-1;

    // case 0,1,2,3 네가지,  →, ↓, ←, ↑    
    while(reCnt<mFullCnt)
    {
        re[reCnt] = matrix[i][j];

        switch (c)
        {
        case 0:
            j++;
            reCnt++;
            if(j>right){
                j--;
                i++;
                top++;
                c = 1;
            }
            break;
        case 1:
            i++;
            reCnt++;
            if(i>bottom){
                i--;
                j--;
                right --;
                c= 2;
            }
            break;
        case 2:
            j--;
            reCnt++;
            if(j < left){
                j++;
                i--;
                bottom --;
                c= 3;
            }
            break;
        case 3:
            i--;
            reCnt++;
            if(i < top){
                i++;
                j++;
                left ++;
                c= 0;
            }
            break;
        default:
            break;
        }
    }
    return re;
}
