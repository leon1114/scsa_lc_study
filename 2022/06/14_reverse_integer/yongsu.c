#include <stdio.h>
#include <string.h>

// 문제가 하라는 대로 품

long long my_power(int num, int exp)
{
    int i;
    long long ans = 1;
    for (i = 0; i < exp; i++)
    {
        ans *= num;
    }
    return ans;
}

int reverse(int x){
    char buffer[15];
    int i;
    int len;
    int negative = 0;

    long long x_longlong = (long long) x;

    long long ans = 0;

    for (i = 0; i < 15; i++) buffer[i] = 0;

    if (x_longlong < 0) {
        x_longlong = -x_longlong;
        negative = 1;
    }

    sprintf(buffer, "%llu", x_longlong);

    len = strlen(buffer);

    for (i = len - 1; i >= 0; i--) ans += ((int)buffer[i] - 48) * my_power(10, i);

    if (negative) ans = -ans;

    if (ans >= my_power(2, 31) - 1 || ans <= -(my_power(2, 31) - 1)) ans = 0;

    return (int) ans;
}

// Runtime: 0 ms, faster than 100.00% of C online submissions for Reverse Integer.
// Memory Usage: 5.8 MB, less than 11.46% of C online submissions for Reverse Integer.