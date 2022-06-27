#include <stdio.h>


// Runtime: 3 ms, faster than 68.68% of C online submissions for Divide Two Integers.
// Memory Usage: 5.6 MB, less than 52.14% of C online submissions for Divide Two Integers.

/*
    나누는 수의 제곱수 중 가능한 가장 큰 수를 계속 빼서 그걸로 인수분해 하는 방식으로 구현
    ex. 100 / 3 = 3 * (3^3 + 3 + 3) + 1 ==> quotient = 3^3 + 3 + 3 = 33
        10 / 3 = 3 * (3^1) + 1 ==> quotient = 3^1 = 3
 */

long long my_pow(long long base, long long exp) {
    int prod = 1;
    for (int i = 0; i < exp; i++) {
        prod *= base;
    }
    return prod;
}

long long find_max_exp(long long dividend, long long divisor) {
    long long cnt = 0;
    long long prod = 1;
    long long temp;
    for (int i = 1; ; i++) {
        prod = prod * divisor;
        if (prod >= dividend) {
            break;
        }
        cnt++;
    }
    return cnt;
}

int divide(int dividend, int divisor){
    long long ans = 0;
    long long temp_dividend = dividend > 0 ? (long long) dividend : -((long long) dividend);
    long long temp_divisor = divisor > 0 ? (long long) divisor : -((long long) divisor);

    if (temp_dividend == 0) ans = 0;
    else if (temp_divisor == 1) ans = temp_dividend;
    else {
        while (temp_dividend >= temp_divisor) {
            int max_exp = find_max_exp(temp_dividend,  temp_divisor);
            temp_dividend -= my_pow(temp_divisor, max_exp);
            ans += my_pow(temp_divisor, max_exp - 1);
        }
    }

    if (dividend < 0 && divisor > 0) ans = -ans;
    else if (dividend > 0 && divisor < 0) ans = -ans;

    if (ans > 2147483647) ans = 2147483647;
    else if (ans < -2147483648) ans = -2147483648;

    return (int) ans;
}

int main(void) {
    printf("%d\n", divide(10, 3)); // 2
    printf("%d\n", divide(100, 3)); // 33
    printf("%d\n", divide(100, -3)); // -33
    printf("%d\n", divide(2147483647, 2)); // 1073741823
    return 0;
}