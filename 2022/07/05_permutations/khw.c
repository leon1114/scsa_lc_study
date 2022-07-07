/*
구현은 쉽게 했는데, 전역변수 초기화 안해주면 Runtime 에러 나는거 모르고 계속 삽질했네...ㅠ
Runtime: 25 ms, faster than 16.75% of C online submissions for Permutations.
Memory Usage: 7.3 MB, less than 46.89% of C online submissions for Permutations.
*/
int count =0;

void DFS(int idx, int * per,  int* nums, int numsSize, int* idxArr, int** re){

    if(idx == numsSize)
    {
        re[count] = (int*)malloc(sizeof(int)*numsSize);
        for(int i =0; i < numsSize; i++){
            re[count][i] = per[i];
        }
        count++;
        return;
    }

    for(int i =0; i<numsSize; i++)
    {
        if(idxArr[i]==1)continue;
        idxArr[i]=1;
        per[idx]=nums[i];
        DFS(idx+1,per,nums,numsSize, idxArr, re);
        idxArr[i]=0;
    }
}

int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int permutationSize = 1;
    for(int i = 1; i <= numsSize ; i++){
        permutationSize *= i;
    }

    * returnSize = permutationSize;
    * returnColumnSizes = (int*)malloc(sizeof(int)* permutationSize);
    for(int i = 0 ; i<permutationSize; i++)
    {
        (*returnColumnSizes)[i] = numsSize;
    }

    int ** re;
    re = (int**)malloc(sizeof(int*) * permutationSize);

    int idxArr[6]={0,};
    int per[6];
    count =0;
    DFS(0, per , nums, numsSize, idxArr, re);

    return re;
}
