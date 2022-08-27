
/*
Runtime: 14 ms, faster than 22.73% of C online submissions for Word Break.
Memory Usage: 5.8 MB, less than 88.18% of C online submissions for Word Break.

처음에 DFS로 하다가 timelimit 나서 DP로 변경

*/



int compare(const void *a, const void *b)
{
    return strcmp((char *)a, (char *)b);    
}

bool DFS(char * s, char (*sortedWordDict)[21], int wordDictSize, int * charIdx){

//    if(s[0]=='\0')return true;

    for (int i = charIdx[s[0]-'a']; i < wordDictSize; i++)
    {
        if(i == -1) break;
        if(s[0]!= sortedWordDict[i][0])return false;
        for (int j = 0;; j++)
        {
            if(s[j]=='\0' && sortedWordDict[i][j]== '\0') return true;
            else if(s[j]=='\0') break;
            else if(sortedWordDict[i][j]=='\0'){
                //다음 단어로 넘어가기
                if(DFS( &s[j], sortedWordDict, wordDictSize, charIdx ) ) return true;
                else break;
            }
            else if(s[j] != sortedWordDict[i][j]) break;
        }
    }
    return false;
}

bool getDict(char * s, int start, int end, char (*sortedWordDict)[21], int wordDictSize, int * charIdx){
    
    for (int i = charIdx[s[start]-'a']; i < wordDictSize; i++)
    {
        if(i == -1) break;
        if(s[start]!= sortedWordDict[i][0]) break;
        for (int j = start, k = 0; j<=end; j++, k++)
        {
            if(j==end && sortedWordDict[i][k]== '\0') return true;
            else if(s[j]=='\0') break;
            else if(s[j] != sortedWordDict[i][k]) break;
        }
    }
    
    return false;
}


bool wordBreak(char * s, char ** wordDict, int wordDictSize){

    char sortedWordDict[wordDictSize][21];
    for (int i = 0; i < wordDictSize; i++)
    {
        strcpy(sortedWordDict[i],wordDict[i]);
    }
    qsort(sortedWordDict,wordDictSize,sizeof(sortedWordDict[0]),compare);
    int charIdx[26];
    memset(charIdx, -1, sizeof(int)*26);
    
    for (int i = wordDictSize-1; i >= 0; i--)
    {
        //문자 idx 저장
        charIdx[sortedWordDict[i][0]-'a'] = i;
    }
    //    return DFS(s, sortedWordDict, wordDictSize, charIdx);
    int sLen = strlen(s);
    
    bool dp[sLen+1];
    for (int i = 0; i <= sLen; i++)
    {
        dp[i]= false;
    }
    dp[0] = true;

    for (int i = 1; i <= sLen; i++)
    {
        for (int j = 0; j<i; j++)
        {
            if(dp[j] && getDict(s, j, i, sortedWordDict, wordDictSize, charIdx)){
                dp[i] = true;
                break;
            }
        }        
    }    

    return dp[sLen];

}

