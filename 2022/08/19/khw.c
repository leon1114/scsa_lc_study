/*
Runtime: 3 ms, faster than 66.67% of C online submissions for Word Break II.
Memory Usage: 6.6 MB, less than 55.56% of C online submissions for Word Break II.

어제 time Limit 났던 DFS 코드 이용해서 풀었음
난 어제 문제가 더 어려웠던것 같음 ㅋㅋ
*/

int compare(const void *a, const void *b)
{
    return strcmp((char *)a, (char *)b);    
}

bool DFS(char * s, char (*sortedWordDict)[21], int wordDictSize, int * charIdx, char** re, char* temp, int sLen, int * returnSize, char * tmp){

//    if(s[0]=='\0')return true;

    for (int i = charIdx[s[0]-'a']; i < wordDictSize; i++)
    {
        if(i == -1) break;
        if(s[0]!= sortedWordDict[i][0])return false;
        int wordLen = strlen(sortedWordDict[i]);
        for (int j = 0;j<=wordLen; j++)
        {
            if(s[j]==sortedWordDict[i][j] && s[j]!=NULL){
                temp[j] = sortedWordDict[i][j];
            }
            else if(s[j]=='\0' && sortedWordDict[i][j]== '\0'){
                //temp랑 복사하기
                temp[j]= '\0';
                
                re[*returnSize] = (char *)malloc(sizeof(char)*(strlen(tmp))+1);
                strcpy(re[*returnSize],tmp);
                (*returnSize)++;
                break;
            }
            else if(s[j]=='\0') break;
            else if(sortedWordDict[i][j]=='\0'){
                //다음 단어로 넘어가기
                temp[j] = ' ';
                DFS( &s[j], sortedWordDict, wordDictSize, charIdx, re, &temp[j+1], sLen, returnSize, tmp);
            }
            else if(s[j] != sortedWordDict[i][j]) break;
        }
        
    }
    return false;
}


char ** wordBreak(char * s, char ** wordDict, int wordDictSize, int* returnSize){

    int sLen = strlen(s);
    char sortedWordDict[wordDictSize][21];
    for (int i = 0; i < wordDictSize; i++)
    {
        strcpy(sortedWordDict[i],wordDict[i]);
    }
    qsort(sortedWordDict,wordDictSize,sizeof(sortedWordDict[0]),compare);
    int charIdx[26];
    memset(charIdx, -1, sizeof(int)*26);
    *returnSize = 0;

    for (int i = wordDictSize-1; i >= 0; i--)
    {
        //문자 idx 저장
        charIdx[sortedWordDict[i][0]-'a'] = i;
    }
    int check[wordDictSize];
    memset(check, 0, sizeof(int)*wordDictSize);

    char ** re = (char **) malloc(sizeof(char*)*10000);
    char * temp = (char *)malloc(sizeof(char)*50);
    DFS(s, sortedWordDict, wordDictSize, charIdx, re, temp, sLen, returnSize, temp);
    
    return re;
    
}
