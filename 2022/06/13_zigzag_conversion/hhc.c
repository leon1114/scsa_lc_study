#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Runtime: 7 ms, faster than 65.75% of C online submissions for Zigzag Conversion.
// Memory Usage: 6.7 MB, less than 47.72% of C online submissions for Zigzag Conversion.
char * convert(char * s, int numRows){
    int len = strlen(s);
    char *ptr = malloc(len + 1);
    int one_pat = (numRows - 1) * 2;
    int new_idx = 0;
    if (numRows == 1) return s;
    for(int j = 0; j < numRows; j++) {  // line by line
        for(int i = 0; i < len && i+j< len; i += one_pat) { // each row
            if ((i+j)%one_pat == 0 || (i+j)%one_pat == numRows-1) {
                ptr[new_idx] = s[i+j];
                new_idx++;
            } else {
                ptr[new_idx] = s[i+j];
                new_idx++;
                
                if(new_idx+1 < len && i + one_pat-j < len) {
                    ptr[new_idx] = s[i + one_pat-j];
                    new_idx++;
                }
            }
        }    
    }
    ptr[len] = '\0';
    return(ptr);
}

int main()
{
    printf("%s = PAHNAPLSIIGIYIR\n", convert("PAYPALISHIRING", 3));
    printf("%s = PINALSIGYAHRPI\n", convert("PAYPALISHIRING", 4));
    printf("%s = P\n", convert("P", 1));
    return 0;
}
