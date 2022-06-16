#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Runtime: 1158 ms, faster than 5.21% of C online submissions for Regular Expression Matching.
// Memory Usage: 5.7 MB, less than 35.94% of C online submissions for Regular Expression Matching.
bool isMatch(char * s, char * p){
    int len = strlen(s);
    int p_len = strlen(p);
    char bef_ast;
    bool ret = false;
    bool ast_ret = false;
    int i = 0;
    if (s[i] == *p || *p == '.' || (p_len > 1 && p[1] == '*')) {
        ret = true;
        for(int j = 0; j < p_len; j++) {
            if (p[j+1] == '*') {
                j++;
                bef_ast = p[j-1];
                for(int k = 0; i + k <= len; k++) {
                    if (k == 0 || s[i+k-1] == bef_ast || bef_ast == '.') {
                        ast_ret = isMatch(s+i+k, p+j+1);
                        if (ast_ret) return true;
                        if (bef_ast != '.' && s[i+k] != bef_ast) break;
                    }
                }
            }
            else if (p[j] == s[i]) {
                i++;
                continue;
            }
            else if (p[j] == '.' && i < len) {
                i++;
                continue;
            } else return false;
            if (i == len) return false;
        }
        if (i != len) ret = false;
    }
    return ret;
}

int main()
{
    printf("%d = 0\n", isMatch("aa", "a"));
    printf("%d = 1\n", isMatch("aa", "a*"));
    printf("%d = 1\n", isMatch("ab", ".*"));
    printf("%d = 1\n", isMatch("aacef", ".*ef"));
    printf("%d = 1\n", isMatch("bdptef", ".*bd.*ef"));
    printf("%d = 1\n", isMatch("bdpeftefpppt", "bd.*efp*t"));
    printf("%d = 1\n", isMatch("pppt", "p*t"));
    printf("%d = 1\n", isMatch("aaa", "a*a"));
    printf("%d = 1\n", isMatch("aab", "c*a*b*"));
    printf("%d = 0\n", isMatch("ab", ".*c"));
    printf("%d = 0\n", isMatch("ippi", "p*."));
    printf("%d = 0\n", isMatch("aaa", "aaaa"));
    printf("%d = 0\n", isMatch("a", ".*..a*"));
    printf("%d = 1\n", isMatch("a", "ab*"));
    printf("%d = 0\n", isMatch("caaaaccabcacbaac", ".*..*bba.*bc*a*bc"));
    return 0;
}
