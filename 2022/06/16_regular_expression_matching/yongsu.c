#include <stdio.h>
#include <stdbool.h>

// Runtime: 65 ms, faster than 16.32% of C online submissions for Regular Expression Matching.
// Memory Usage: 5.7 MB, less than 20.53% of C online submissions for Regular Expression Matching.

int my_strlen(char * s) {
    int len = 0;
    while (s[len]) len++;
    return len;
}

bool dfs(char * s, char * p) {
    bool s_is_done = (my_strlen(s) == 0); // s가 끝났는지 확인
    bool p_is_done = (my_strlen(p) == 0); // p가 끝났는지 확인
    
    if (p_is_done) return s_is_done; // p가 끝났는데 s도 끝났으면 성공, 아니면 실패

    if (p[1] == '*') { // *은 문자열이 반복되지 않거나 (0개) 반복될 경우(1개 이상) 둘 다 확인해야함
        // 0개라고 가정하고 패턴 2칸 건너뛰기, 얘는 s가 끝나도 p가 끝나면 통과기 때문에 s가 끝났는지 확인 안 해도됨
        return (dfs(s, p + 2)) || // 두 케이스 중 하나만 만족하면 되니까 OR 연산
        // s가 안끝났고, 똑같은 문자가 1개 이상이라고 가정하고 s를 한칸씩 움직이면서 체크해야하는데, 이 때 s첫글자랑 p첫글자가 같거나, p첫글자가 .이어야 함. 같다면 다음 문자 확인
        (!s_is_done && (s[0] == p[0] || p[0] == '.') && dfs(s + 1, p));
    } else {
        // s가 안끝났고, s와 p 첫글자가 같거나 p 첫글자가 .이면, 통과하고 그 다음 문자열 비교
        return !s_is_done && (s[0] == p[0] || p[0] == '.') && dfs(s + 1, p + 1);
    }
}

bool isMatch(char * s, char * p) {
    return dfs(s, p);
}

// int main(void) {
//     printf("%d\n", isMatch("aa", "a"));  //0
//     printf("%d\n", isMatch("aa", "a*")); //1
//     printf("%d\n", isMatch("aaaaaa", "a*")); //1
//     printf("%d\n", isMatch("aaa", "a*a")); //1
//     printf("%d\n", isMatch("aaaaaa", ".*")); //1
//     printf("%d\n", isMatch("ab", ".*")); //1
//     printf("%d\n", isMatch("aab", "c*a*b")); //1
//     return 0;
// }