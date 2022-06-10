#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Runtime: 380 ms, faster than 18.74% of C online submissions for Longest Palindromic Substring.
// Memory Usage: 6 MB, less than 89.29% of C online submissions for Longest Palindromic Substring.
char *substring(char *string, int position, int length)
{
   char *p;
   int c;
 
   p = malloc(length+1);
   
   if (p == NULL)
   {
      printf("Unable to allocate memory.\n");
      exit(1);
   }
 
   for (c = 0; c < length; c++)
   {
      *(p+c) = *(string+position-1);      
      string++;  
   }
 
   *(p+c) = '\0';
 
   return p;
}

int is_palin(char *string, int pos_s, int pos_e) {
    int len = pos_e - pos_s + 1;
    int ret = 1;
    for(int i = 0; i <= len / 2; i++) {
        if (string[pos_s + i] != string[pos_e - i]) {
            ret = 0;
            break;
        }
    }
    return ret;
}
char * longestPalindrome(char * s) {
    int len = strlen(s);
    char * sub;
    for(int l = len; l >= 1; l--) {
        for(int i = 0; i <= len - l; i++)
        {
            if (is_palin(s, i, i + l - 1)) {
                sub = substring(s, i + 1, l);
                return sub;
            }
        }
    }
    return sub;
}

int main()
{
    char s[] = "cbbd";
    printf("%s = bb\n", longestPalindrome(s));
    printf("%s = bab\n", longestPalindrome("babad"));
    printf("%s = abcba\n", longestPalindrome("abcdrhdophb04abcbatncv1"));
    // printf("%d", is_palin("cbbd", 0, 3));
    // printf("%d", is_palin("babad", 1, 3));
    // printf("%d", is_palin("babad", 1, 2));
    // printf("%d", is_palin("babad", 0, 5));
    return 0;
}
