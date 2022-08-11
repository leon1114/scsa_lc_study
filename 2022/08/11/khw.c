/*
Runtime: 803 ms, faster than 6.25% of C online submissions for Palindrome Partitioning.
Memory Usage: 89.8 MB, less than 6.25% of C online submissions for Palindrome Partitioning.
*/



int checkPalindrome(char *s, int start, int end){
    while(start <= end){
        if (s[start]!= s[end]){
            return 0;
        }
        start++;
        end--;
    }
    return 1;
}

char *** partition(char * s, int* returnSize, int** returnColumnSizes){
    int sLen = strlen(s);
    int maxPartitionCnt = 1<<(sLen-1);
    char *** ret = (char***)malloc(sizeof(char**)*maxPartitionCnt);
    *returnSize= 0;
    (*returnColumnSizes) = (int*)malloc(sizeof(int)*maxPartitionCnt);

    //patition 길이
    //나누는 위치를 비트 마스크로 구분 
    
    for(int splitPoint = maxPartitionCnt-1; splitPoint>=0; splitPoint--){
        char ** subStr = (char**)malloc(sizeof(char*)*sLen);
        int start = 0;
        int subIdx =0;
        int valid = 1;

        for (int i = 0; i < sLen-1; i++)
        {
            if( ((1<<i)&splitPoint) > 0 ){
                if(checkPalindrome(s,start,i)){
                    subStr[subIdx] = (char*)malloc(sizeof(char)*(i-start+1+1));
                    memcpy(&subStr[subIdx][0], &s[start], (i-start+1)*sizeof(char));
                    subStr[subIdx][i-start+1] = '\0';
                    start = i+1;
                    subIdx++;
                } else {
                    valid = 0;
                    break;
                }
            } 
        }
        //마지막 영역 확인
        if(valid == 1 && checkPalindrome(s,start, sLen-1)){
            subStr[subIdx] = (char*)malloc(sizeof(char)*(sLen-start+1+1));
            memcpy(&subStr[subIdx][0], &s[start], (sLen-start+1)*sizeof(char));
            subStr[subIdx][sLen-start+1] = '\0';
            subIdx++;
        } else {
            valid = 0;
        }

        //해당 케이스가 가능하다면 결과값에 추가해 줌
        if(valid ==1){
            ret[*returnSize] = subStr;
            (*returnColumnSizes)[*returnSize] = subIdx;
            (*returnSize)++;
        }
    }
    
    return ret;
}
