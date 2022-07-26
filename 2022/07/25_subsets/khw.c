
/*
Runtime: 11 ms, faster than 29.70% of C online submissions for Subsets.
Memory Usage: 6.2 MB, less than 89.11% of C online submissions for Subsets.

0~배열 사이즈로 부분집합 만들게 백트랙킹 사용해서 풀었음
*/


void makeSubSet(int* nums, int numsSize, int* rSize, int** returnColumnSizes, int** re, int RCSize, int rIdx, int * temp, int idx)
{
    if(RCSize == rIdx)
    {
        re[(*rSize)] = (int*)malloc(RCSize*sizeof(int));
        if(RCSize == 0) re[(*rSize)]= NULL;
        for (size_t i = 0; i < RCSize; i++)
        {
            re[(*rSize)][i]=temp[i];
        }
        (*returnColumnSizes)[(*rSize)] = RCSize;
        (*rSize)++;
    } else if(rIdx > RCSize){
        return;
    } else {

        for (size_t i = idx+1; i < numsSize; i++)
        {
            temp[rIdx]=nums[i];
            makeSubSet(nums, numsSize, rSize, returnColumnSizes, re, RCSize, rIdx+1, temp, i);
        }
    }
}


int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    
    *returnSize = 1<<numsSize;    
    int ** re = (int **)malloc(sizeof(int*)*(*returnSize));    
    *returnColumnSizes = (int*)malloc(sizeof(int)*(*returnSize));
    
    int rSize =0;
    int temp[numsSize];
    for(int i =0; i<=numsSize ; i++)
    {
        makeSubSet(nums, numsSize, &rSize, returnColumnSizes, re, i, 0, temp,-1);
    }

    if(*returnSize != rSize)printf("Error\n");
    return re;
}
