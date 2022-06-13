#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char board[2000][2000];
int row_column_index[2000];
char ans[2000];

void init()
{
    int i, j;
    for (i = 0; i < 2000; i++)
    {
        memset(board[i], 0, strlen(board[i]));
        row_column_index[i] = 0;
    }
    for (i = 0; i < 2000; i++)
    {
        ans[i] = 0;
    }
}

char * convert(char * s, int numRows)
{
    int i, j;
    int len = strlen(s);

    int row_increment = -1; // 1 for ++, -1 for --
    int row_num = 0;

    init();

    if (numRows == 1) return s;

    for (i = 0; i < len; i++)
    {
        board[row_num][row_column_index[row_num]] = s[i];
        row_column_index[row_num]++;
        if (row_num == numRows - 1 || row_num == 0) row_increment = -row_increment;
        if (row_increment == 1) row_num++;
        else row_num--;
    }

    int cnt = 0;

    for (i = 0; i < numRows; i++)
    {
        for (j = 0; j < len; j++)
        {
            if (board[i][j] == 0) break;
            ans[cnt++] = board[i][j];
        }
    }

    return ans;
}

// int main(void)
// {
//     printf("hello world\n");
//     printf("%s\n", convert("PAYPALISHIRING", 3));
//     printf("%s\n", convert("PAYPALISHIRING", 4));
//     printf("%s\n", convert("AB", 1));
//     printf("%s\n", convert("uhyxutlx", 8));
//     return 0;
// }


// Runtime: 50 ms, faster than 15.20% of C online submissions for Zigzag Conversion.
// Memory Usage: 8.4 MB, less than 16.63% of C online submissions for Zigzag Conversion.