#include <stdio.h>

long long my_power(int num, int exp)
{
    int i;
    long long ans = 1;
    for (i = 0; i < exp; i++) ans *= num;
    return ans;
}

int my_strlen(char * s)
{
    int len = 0;
    while(s[len]) len++;
    return len;
}


int myAtoi(char * s){
    long long ans = 0;

    int len = my_strlen(s);

    char buffer[210];
    int buffer_cnt = 0;

    int negative = 0;
    int positive = 0;

    int number_reached = 0;
    int word_preceded = 0;
    int blank_should_be_over = 0;

    int i;

    for (i = 0; i < 210; i++)
    {
        buffer[i] = 0; // 초기화
    }

    for (i = 0; i < len; i++)
    {
        if (s[i] >= '0' && s[i] <= '9') // 숫자일 경우
        {
            if (!number_reached && word_preceded == 1) break; // 처음으로 숫자가 나왔는데, 이미 문자가 나왔을 경우
            if (!blank_should_be_over) blank_should_be_over = 1; // 빈 칸은 이제 그만나와야함
            buffer[buffer_cnt++] = s[i]; // buffer에 숫자 넣기
            if (!number_reached) number_reached = 1; // 숫자가 나왔다고 체크
        }
        else // 아닐 경우
        {
            if (number_reached) break; // 숫자가 나왔었는데 문자가 나온 경우
            if (s[i] == ' ') 
            {
                if (blank_should_be_over) break; // 빈 칸이 그만 나와야 되는데 또 나온 경우
                continue; // 빈 칸이 나와도 되면(leading이면) 계속 탐색
            }
            if (s[i] == '-')
            {
                if (!blank_should_be_over) blank_should_be_over = 1; // 빈 칸은 이제 그만나와야함
                if (positive) break; // +가 나왔는데 -가 또 나온 경우
                if (!negative) negative = 1; // -가 나왔다고 체크
                else break;
            }
            else if (s[i] == '+')
            {
                if (!blank_should_be_over) blank_should_be_over = 1; // 빈 칸은 이제 그만나와야함
                if (negative) break; // -가 나왔는데 +가 또 나온 경우
                if (!positive) positive = 1; // +가 나왔다고 체크
                else break;
            }
            else
            {
                if (!blank_should_be_over) blank_should_be_over = 1; // 빈 칸은 이제 그만나와야함
                if (!number_reached) break; // 숫자가 나왔는데 문자가 나온 경우
            }
        }
    }

    int buffer_len = my_strlen(buffer);

    for (i = 0; i < buffer_len; i++)
    {
        if (buffer[i] == '0') continue;
        else if (buffer_len - i - 1 > 10) { // 계산하기 너무 크다면
            if (negative) ans = my_power(2, 31); // 음수일 경우 음수 최대치의 절대값 넣기
            else ans = my_power(2, 31) - 1; // 양수일 경우 양수 최대치 넣기
            break;
        }
        else ans += (buffer[i] - 48) * my_power(10, buffer_len - i - 1); // 자릿수에 따라 10진수 계산
    }
    
    if (negative) ans = -ans; // 음수일 경우

    if (ans >= my_power(2, 31) - 1) ans = my_power(2, 31) - 1; // 답이 최대값보다 크다면
    else if (ans <= -my_power(2, 31)) ans = -my_power(2, 31); // 답이 최소값보다 크다면

    return (int) ans;
}

// int main(void)
// {
//     printf("42 : %d\n", myAtoi("42"));
//     printf("        -42 : %d\n", myAtoi("       -42"));
//     printf("4193 with words : %d\n", myAtoi("4193 with words"));
//     printf("words and 987 : %d\n", myAtoi("words and 987"));
//     printf("-91283472332: %d\n", myAtoi("-91283472332"));
//     printf("+-12: %d\n", myAtoi("+-12"));
//     printf("-000000000000000000000000000000000000000000000000001: %d\n", myAtoi("-000000000000000000000000000000000000000000000000001"));
//     printf(" +  413: %d\n", myAtoi("  +  413"));
//     printf("-9223372036854775809: %d\n", myAtoi("-9223372036854775809"));
//     return 0;
// }


// Runtime: 6 ms, faster than 33.81% of C online submissions for String to Integer (atoi).
// Memory Usage: 5.7 MB, less than 35.47% of C online submissions for String to Integer (atoi).