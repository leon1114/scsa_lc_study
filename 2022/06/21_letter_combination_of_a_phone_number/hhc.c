#include <stdio.h>
#include <stdlib.h>

// Runtime: 4 ms, faster than 37.65% of C online submissions for Letter Combinations of a Phone Number.
// Memory Usage: 6.1 MB, less than 27.38% of C online submissions for Letter Combinations of a Phone Number.

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

const char* map_digits[8] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

int length(char * str) {
    int cnt = 0;
    while(*str != '\0') {cnt++;str++;}
    return cnt;
}

char ** dfs(char*** sol, char* digits, int* returnSize){
    // digits[0] == null, then return empty array
    if (digits[0] == '\0') {
        return *sol;
    }
    // 새로 return malloc
    // digits[0]에 대한 character 3~4개에 대해서
    // map_ptr = "def"
    char *map_ptr = (char*)map_digits[(int)(digits[0] - '2')];
    int map_len = length(map_ptr), tmp_sol_len;
    (*returnSize) *= map_len;
    char ** ret = (char **)malloc(sizeof(char*) * (*returnSize));
    int new_idx = 0;
    tmp_sol_len = length((*sol)[0]);
    for (int j = 0; j < map_len; j++) {
        // 기존 sol에 대해서
        // sol[i] = "ad"
        for (int i = 0; i < ((*returnSize) / map_len); i++) {
            // concatenate map_ptr[j], sol[i]
            ret[new_idx] = (char *)malloc(sizeof(char) * (tmp_sol_len + 2));
            for(int k = 0; k < tmp_sol_len; k++) {
                ret[new_idx][k] = (*sol)[i][k];
            }
            ret[new_idx][tmp_sol_len] = map_ptr[j];
            ret[new_idx++][tmp_sol_len + 1] = '\0';
        }
    }
    free(*sol);
    return dfs(&ret, digits + 1, returnSize);
}


char ** letterCombinations(char * digits, int* returnSize){
    if (digits[0] == '\0') {
        *returnSize = 0;
        return (char **)malloc(sizeof(char*) * (*returnSize));
    }
    
    *returnSize = 1;
    char ** sol = (char **)malloc(sizeof(char*) * (*returnSize));
    sol[0] = (char*)malloc(sizeof(char));
    sol[0][0] = '\0';
    sol = dfs(&sol, digits, returnSize);
    
    return sol;
}


int main()
{
    int returnSize;
    char ** sol = letterCombinations("9999", &returnSize);
    for(int i = 0; i < returnSize; i++) {
        printf("%s ", sol[i]);
    }
    printf("\n");
    return 0;
}
