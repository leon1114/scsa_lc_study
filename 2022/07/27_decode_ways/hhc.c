// Runtime: 0 ms, faster than 100.00% of C online submissions for Decode Ways.
// Memory Usage: 5.7 MB, less than 31.33% of C online submissions for Decode Ways.

int dfs(char * s, int idx, long long* chk){
    if (chk[idx] != -1) {
        return chk[idx];
    } else if (s[idx] == '0') {
        chk[idx] = 0;
        return 0;
    } else if (s[idx] == '\0' || s[idx + 1] == '\0') {
        return 1;
    } else if (s[idx] == '1' || (s[idx] == '2' && s[idx + 1] <= '6')) {
        chk[idx + 2] = dfs(s, idx + 2, chk);
        chk[idx + 1] = dfs(s, idx + 1, chk);
        chk[idx] = chk[idx + 1] + chk[idx + 2];
        return chk[idx];
    }
    chk[idx] = chk[idx + 1] = dfs(s, idx + 1, chk);
    return chk[idx];
}

int numDecodings(char * s){
    long long chk[103];
    for(int i = 0; i < 102; i++) chk[i] = -1;
    return dfs(s, 0, (long long*)chk);
}
