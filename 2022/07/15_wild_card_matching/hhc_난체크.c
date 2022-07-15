// Time limit exceeded
// 술마시고 우영우 봐야하는 관계로 췤

bool isMatch(char * s, char * p){
    bool ret = false;
    int s_len = strlen(s);
    if (s[0] == '\0' && p[0] == '\0') return true;
    else if (p[0] != '*' && s[0] == '\0' || p[0] == '\0') return false;
    else if (p[0] == '*') {
        int j = 1;
        // '*'이 2개 이상일 경우 1개만 적용
        while (p[j] == '*') j++;
        for (int i = 0; i <= s_len; i++) {
            if (isMatch(s+i, p+j)) {
                ret = true;
                break;
            }
        }
    }
    else if (s[0] == p[0] || p[0] == '?') {
        ret = isMatch(s+1, p+1);
    }
    return ret;
}
