// 멀록 + 뤡록 = VERY SLOW
// Runtime: 0 ms, faster than 100.00% of C online submissions for Count and Say.
// Memory Usage: 6.2 MB, less than 79.38% of C online submissions for Count and Say.

char * arr_say_str[31];

char * say(char * prev_str, int n) {
    int cnt = 0, str_len = strlen(prev_str), say_len = 1;
    char * say_str = (char*)malloc(sizeof(char) * (str_len * 2 + 1));
    char tmp_ch = prev_str[0];
    
    for(int i = 0; i <= str_len; i++) {
        if (tmp_ch != prev_str[i]) {
            say_len += 2;
            say_str[say_len - 3] = '0' + cnt;
            say_str[say_len - 2] = tmp_ch;
            
            tmp_ch = prev_str[i];
            cnt = 1;
        } else {
            cnt++;
        }
    }
    say_str = (char*)realloc(say_str, sizeof(char) * say_len);
    say_str[say_len - 1] = '\0';
    arr_say_str[n] = say_str;
    return say_str;
}

char * countAndSay(int n){
    char *ret;
    if (arr_say_str[n] != NULL) return arr_say_str[n];
    if (n == 1) {
        ret = (char*)malloc(sizeof(char) * 2);
        ret[0] = '1'; ret[1] = '\0';
        return ret;
    }
    char * prev_str = countAndSay(n - 1);
    ret = say(prev_str, n);
    return ret;
}
