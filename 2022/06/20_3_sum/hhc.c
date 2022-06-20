#include <stdio.h>
#include <stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

// Runtime: 257 ms, faster than 33.26% of C online submissions for 3Sum.
// Memory Usage: 20.7 MB, less than 74.68% of C online submissions for 3Sum.
// 개같이 많이 제출해봄 ㅎㅎ

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    *returnSize = 0;
    int tmp_size = numsSize * 2;
    int** sol = (int **)malloc(sizeof(int*) * tmp_size);
    if (numsSize < 3) return sol;
    
    int left, mid, right;
    qsort(nums, numsSize, sizeof(int), cmpfunc);
    
    int tmp = 0;
    for (left = 0; left < numsSize; left++){
        mid = left + 1;
        right = numsSize - 1;
        while (left < mid && mid < right) {
            if (nums[left] > 0) break;
            if (nums[left] + nums[mid] + nums[right] > 0) {
                right--;
            } else if(nums[left] + nums[mid] + nums[right]  < 0) {
                tmp = nums[mid];
                while(mid < numsSize && nums[mid] == tmp) mid++;
            } else { // threesum success
                if ((*returnSize) == tmp_size) {
                    tmp_size *= 2;
                    sol = (int **)realloc(sol, tmp_size * sizeof(int *));
                }
                sol[(*returnSize)] = malloc(sizeof(int) * 3);
                sol[(*returnSize)][0] = nums[left];
                sol[(*returnSize)][1] = nums[mid];
                sol[(*returnSize)++][2] = nums[right];
                tmp = nums[right];
                while(right > 0 && nums[right] == tmp) right--;
            }
        }
        while(left + 1 < numsSize && nums[left] == nums[left + 1]) left++;
    }
    
    sol = (int **)realloc(sol, (*returnSize) * sizeof(int *));
    *returnColumnSizes = malloc((*returnSize) * sizeof(int));    
    for (int i = 0; i < *returnSize; ++i) (*returnColumnSizes)[i] = 3;
    return sol;
}


int main()
{
    int returnSize1; int *returnColumnSizes1;
    int** ret1 = threeSum((int[]){-1,0,1,2,-1,-4}, 6, &returnSize1, &returnColumnSizes1);
    printf("ret_size=%d\n", returnSize1);
    for(int i =0; i < returnSize1; i++) {
        for(int j = 0; j < 3; j++){
            printf("%d", ret1[i][j]);
        }
        printf("\n");
    }
    free(ret1);
    
    return 0;
}
