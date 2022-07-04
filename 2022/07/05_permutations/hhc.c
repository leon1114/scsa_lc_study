// // 멀록, 뤨록이 시간 많이 잡아먹는 것 같음. 최적화 더 할 수 있을 것 같은데?
// Runtime: 9 ms, faster than 92.11% of C online submissions for Permutations.
// Memory Usage: 7.3 MB, less than 40.79% of C online submissions for Permutations.

// dfs 내부의 멀록 제거했는데 성능차이는 크게 없음 - 오히려 느려짐?
// Runtime: 14 ms, faster than 68.90% of C online submissions for Permutations.
// Memory Usage: 7.3 MB, less than 35.41% of C online submissions for Permutations.

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int factorial(int n) {
    int ret = 1;
    while(n > 1) ret *= n--;
    return ret;
}

void dfs(int *** ret_arr, int* curr_cnt, int* nums, int numsSize, int* add_nums, int addSize) {
    // numsSize == 0 이면 ret_arr에 해당 add_nums를 멀록해서 쳐넣는다
    if (numsSize == 0) {
        int * tmp = (int*)malloc(sizeof(int) * (addSize));
        for(int i = 0; i < addSize; i++) tmp[i] = add_nums[i];
        (*ret_arr)[(*curr_cnt)++] = tmp;
        return;
    }
    
    int added[6];
    int num_wo_one[6];
    for(int j = 0; j < numsSize; j++) {
        // nums에서 숫자 한개 뺀 array를 만들어서 다음 dfs에 넘김
        int cnt = 0;
        for(int i = 0; i < numsSize; i++) {
            if(i != j) num_wo_one[cnt++] = nums[i];
        }  
        
        // nums의 숫자 하나씩 add_nums에 넣어가면서 dfs
        for(int i = 0; i < addSize; i++) {
            added[i] = add_nums[i];
        }
        added[addSize] = nums[j];
        dfs(ret_arr, curr_cnt, num_wo_one, numsSize - 1, added, addSize + 1);
    }
}

int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int curr_cnt = 0;
    *returnSize = factorial(numsSize);
    int ** ret_arr = (int**)malloc(sizeof(int*) * (*returnSize));
    int * ret_col_arr = (int*)malloc(sizeof(int) * (*returnSize));
    for(int i = 0; i < (*returnSize); i++) {
        ret_col_arr[i] = numsSize;
    }
    *returnColumnSizes = ret_col_arr;
    dfs(&ret_arr, &curr_cnt, nums, numsSize, NULL, 0);
    return ret_arr;
}

