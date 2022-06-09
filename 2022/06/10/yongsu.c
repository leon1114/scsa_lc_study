#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isPalindrome(char * s)
{
    int len = strlen(s);
    int i = 0;

    for (i = 0; i < len / 2; i++)
    {
        if (s[i] != s[len - i - 1])
        {
            return 0;
        }
    }

    return 1;
}

void my_substr(int start, int end, char * src, char * dst)
{
    strncpy(dst, src + start, end - start + 1);
}


char * getPalindrome(int first_index, int last_index, char * s)
{
    static char palindrome[2000] = {};
    memset(palindrome, 0, 2000);
    // String 인덱스 안에 있으면서 한칸씩 좌우로 움직이면서 두 개를 비교한다
    while (first_index >= 0 && last_index < strlen(s) && s[first_index] == s[last_index])
    {
        first_index--; last_index++;
    }
    //strncpy(palindrome, s + first_index + 1, --last_index - ++first_index + 1);

    // 만약 while loop에 안걸렸으면 그 이전 값들이 최대 palindrome 이므로 전 값을 substring해서 리턴한다
    my_substr(first_index + 1, last_index - 1, s, palindrome);
    return palindrome;
}



char * longestPalindrome(char * s)
{
    static char ans[2000] = {0, };
    char tmp_buffer[2000] = {0, };

    memset(ans, 0, 2000);
    memset(tmp_buffer, 0, 2000);

    int tmp_buffer_idx;
    int len = strlen(s);
    int i, j;

    char even_length_candidate[2000];
    char odd_length_candidate[2000];

    memset(even_length_candidate, 0, 2000); // OO OXXO 형태의 짝수 개 후보
    memset(odd_length_candidate, 0, 2000); // OXO OXOXO 형태의 홀수 개 후보
    ans[0] = s[0];

    char * tmp = NULL;

    for (i = 0; i < len - 1; i++)
    {
        memset(even_length_candidate, 0, strlen(even_length_candidate));
        memset(odd_length_candidate, 0, strlen(odd_length_candidate));

        tmp = getPalindrome(i, i + 1, s); // 짝수 개 후보의 palindrome 후보를 구한다
        memcpy(even_length_candidate, tmp, strlen(tmp));
        tmp = getPalindrome(i, i + 2, s); // 홀수 개 후보의 palindrome 후보를 구한다
        memcpy(odd_length_candidate, tmp, strlen(tmp));

        // 더 큰 놈을 저장
        if (strlen(even_length_candidate) > strlen(odd_length_candidate))
        {
            if (strlen(even_length_candidate) > strlen(ans))
            {
                memcpy(ans, even_length_candidate, strlen(even_length_candidate));
            }
        }
        else
        {
            if (strlen(odd_length_candidate) > strlen(ans))
            {
                memcpy(ans, odd_length_candidate, strlen(odd_length_candidate));
            }
        }
    }

    printf("ans : %s\n", ans);

    return ans;
}

Runtime: 380 ms, faster than 18.56% of C online submissions for Longest Palindromic Substring.
Memory Usage: 6.3 MB, less than 48.84% of C online submissions for Longest Palindromic Substring.
Next challenges: