// Runtime: 0 ms, faster than 100.00% of C online submissions for Factorial Trailing Zeroes.
// Memory Usage: 5.6 MB, less than 42.17% of C online submissions for Factorial Trailing Zeroes.
// 인수분해해서 5의 개수만큼 trailing zero가 생김

int trailingZeroes(int n) {
    int fives = 5;
    int cnt_0 = 0;
    while (fives <= n) {
        cnt_0 += n / fives;
        fives = fives * 5;
    }
    return cnt_0;
}
