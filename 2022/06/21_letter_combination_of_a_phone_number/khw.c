/**
Runtime: 2 ms, faster than 55.75% of C online submissions for Letter Combinations of a Phone Number.
Memory Usage: 5.7 MB, less than 78.73% of C online submissions for Letter Combinations of a Phone Number.

 * Note: The returned array must be malloced, assume caller calls free().
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

void dfs(char ** re, char **phone, char *digits, int * returnSize, char *temp, int index, int digitsLen) {
    
    if (index == digitsLen) {
        temp[index] = '\0';
        int tempLen = 0;
        while(temp[tempLen]!=NULL) tempLen++;
        re[(*returnSize)] = (char *)malloc(tempLen + 1);
        myStringCopy(re[(*returnSize)], temp);
        (*returnSize)++;
        return;
    }
    char * phoneChar = phone[digits[index] - '0' - 2];
    int phoneCharLen = 0;
    while(phoneChar[phoneCharLen]!=NULL) phoneCharLen++;

    for (int i = 0; i < phoneCharLen; i++) {
        temp[index] = phoneChar[i];
        dfs(re, phone, digits, returnSize, temp, index + 1, digitsLen);
    }
}

char **letterCombinations(char * digits, int* returnSize){
    * returnSize = 0;
    char * phone[8] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    char ** re = (char **)malloc(sizeof(char *) * 256);
    int digitsLen = 0;
    while(digits[digitsLen]!=NULL) digitsLen++;
    char temp[digitsLen + 1];
    
    if (digitsLen == 0) {
        *returnSize = 0;
        return re;
    }

    dfs(re, phone, digits, returnSize , temp, 0, digitsLen);

    return re;
}

// int main()
// {

//     char digits[3]= "23";
//     int * returnSize = (int*)malloc(sizeof(int*));
//     char ** re;
//     re = letterCombinations(digits, returnSize);

//     for(int i=0; i< *returnSize; i++)
//     {
//         if(i==0) printf("[");
        
//         printf("\"%s\"",re[i]);
//         if(i!=*returnSize-1) printf(", ");
//         else if (i==*returnSize-1) printf("]");
//     }

//     return 0;
// }
