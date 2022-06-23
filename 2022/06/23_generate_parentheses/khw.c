/*
Runtime: 3 ms
Memory Usage: 11.9 MB
*/


char* myStringCopy(char s1[], char s2[]){
    int i = 0;
    while (s2[i] != NULL)
    {
        s1[i] = s2[i];
        i++;
    }
    s1[i] = '\0';
    return s1;
}

int myGetStringLen(char * s)
{
    int len = 0;
    while(s[len]!=NULL) len++;
    return len;
}

void dfs(char ** re, char * temp, int leftParenthesisCount, int rightParenthesisCount, int n, int index, int * returnSize)
{
    if(rightParenthesisCount == n){
        temp[index] = '\0';
        int tempLen = myGetStringLen(temp);
        re[*returnSize] = (char *)malloc(tempLen +1);
        myStringCopy(re[*returnSize],temp);
        (*returnSize)++;
        return;
    }
    char parenthersis[3] ={'(',')'};
    for(int i =0; i < 2; i++){
        if(parenthersis[i]=='(')
        {
            if(leftParenthesisCount>=n) continue;
            temp[index] = parenthersis[i];
            dfs(re,temp, leftParenthesisCount+1,rightParenthesisCount,n,index+1,returnSize);

        } else
        {
            if(rightParenthesisCount>=leftParenthesisCount)continue;
            temp[index] = parenthersis[i];
            dfs(re,temp, leftParenthesisCount,rightParenthesisCount+1,n,index+1,returnSize);
        }
        
    }

}



char ** generateParenthesis(int n, int* returnSize){
    *returnSize =0;
    char ** re = (char **)malloc(sizeof(char *) * 2048);

    char temp[n*2+1];
    int leftParenthesisCount = 0;
    int rigthParenthesisCount = 0;
    int index =0;
    dfs(re, temp, leftParenthesisCount, rigthParenthesisCount , n, index, returnSize);

    return re;
}
