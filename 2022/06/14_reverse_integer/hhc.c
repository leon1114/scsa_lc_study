#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Runtime: 4 ms, faster than 43.15% of C online submissions for Reverse Integer.
// Memory Usage: 5.6 MB, less than 34.40% of C online submissions for Reverse Integer.
#define MAX_DIGIT 10

int power(int b, int pwr) {
    int result = 1;
    while(pwr) { result *= b; pwr--; }
    return result;
}

int sign(int x) {
    return (x > 0) - (x < 0);
}

int reverse(int x) {
    int int_limit[] = {2,1,4,7,4,8,3,6,4,7};
    int max_digit = 0;
    int digits[MAX_DIGIT] = {0, };
    int x_sign = sign(x);
    int rest;
    int ret = 0;
    int cnt_last_zero = 0;
    int is_overflow = 1;
    
    if (x_sign == -1) {
        if (x == -2147483648) return 0;
        rest = -x;
    } else {
        rest = x;
    }
    
    for(int i = MAX_DIGIT - 1; i >= 0; i--) {
        if (max_digit==0) {
            if (rest / power(10, i) > 0) {
                max_digit = i;
                digits[i] = rest / power(10, i);
                rest = rest % power(10, i);
            } else if (i == 0) {
                digits[i] = rest / power(10, i);
                rest = rest % power(10, i);
            }
        } else {
            digits[i] = rest / power(10, i);
            rest = rest % power(10, i);
        }
    }
    
    if (max_digit < MAX_DIGIT - 1) is_overflow = 0;
    else if ((max_digit == MAX_DIGIT - 1) && digits[0] == 2) is_overflow = 1;
    else if (digits[0] > 2) return 0;
    for(int i = 1; i <= max_digit; i++) {
        if (is_overflow) {
            if(digits[i] > int_limit[i]) return 0;
            else if(digits[i] < int_limit[i]) is_overflow = 0;
        }
        if (digits[i] == 0) cnt_last_zero++;
        else cnt_last_zero = 0;
        ret += digits[i] * power(10, max_digit - i);
    }
    
    if (is_overflow && digits[0] == int_limit[max_digit]) return 0;
    ret += digits[0] * power(10, max_digit);
    
    ret = x_sign * ret;
    if (x > 0 != ret > 0) return 0;
    return ret / power(10, cnt_last_zero);
}

int main()
{
    printf("%d = 0\n", reverse(1534236469));
    printf("%d = 321\n", reverse(123));
    printf("%d = -321\n", reverse(-123));
    printf("%d = 0\n", reverse(1000000007));
    printf("%d = 3\n", reverse(300000000));
    printf("%d = 0\n", reverse(-2147483648));
    printf("%d = 0\n", reverse(2147483647));
    printf("%d = 0\n", reverse(1563847412));
    printf("%d = 86723\n", reverse(32768));
    
    return 0;
}
