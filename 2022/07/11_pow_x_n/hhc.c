// Runtime: 0 ms, faster than 100.00% of C online submissions for Pow(x, n).
// Memory Usage: 5.4 MB, less than 99.86% of C online submissions for Pow(x, n).

double dfs(double x, long long l) {
    if (l == 0) return 1;
    if (l % 2 == 0) return dfs(x, l / 2) * dfs(x, l / 2);
    else return dfs(x, l / 2) * dfs(x, l / 2) * x;
}

double myPow(double x, int n){
    long long l = (long long)n;
    if (l < 0) {
        l = -l;
        x = 1/x;
    }
    return dfs(x, l);
}
