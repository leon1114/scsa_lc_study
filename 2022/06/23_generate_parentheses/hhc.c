/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

char ** ret;

char * str_cat(char * a, char * b) {
    
}

char ** generateParenthesis(int n, int* returnSize){
    // 대충 사이즈 잡아서 멀록
    *returnSize = (1<<n);
    ret = (char **)malloc(sizeof(char*) * (*returnSize));
    for(int i = 0; i < *returnSize; i++) {
        ret[i] = (char *)malloc(sizeof(char) * (n * 2 + 1));
    }
    hanoi(0, n, returnSize);
    
    return ret;
}

class Solution {
public:
    vector<string> hanoi(int open_stack, int n) {
        vector<string> ret;
        // open_stack < n, Append '(', then dfs
        if (open_stack < n && n > 0) {
            ret.push_back(hanoi(open_stack + 1, n - 1));
        }

        // open_stack > 0, Append ')', then dfs
        if (open_stack > 0) {
            ret.push_back(hanoi(open_stack - 1, n));
        }
        return ret;
    }
    vector<string> generateParenthesis(int n) {
        
    }
};
