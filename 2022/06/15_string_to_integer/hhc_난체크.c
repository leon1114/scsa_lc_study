#include <stdio.h>
#include <stdlib.h>

int power(int b, int pwr) {
    int result = 1;
    while(pwr) { result *= b; pwr--; }
    return result;
}

int myAtoi(char * s){
    int ret = 0;
    // Read in and ignore any leading whitespace.
    //
    // ' '인 경우 패쓰하다가~
    
    // Check if the next character (if not already at the end of the string) is '-' or '+'.
    // Read this character in if it is either. This determines if the final result is negative or positive respectively.
    //
    // Assume the result is positive if neither is present.
    int is_negative = 0;
    // '-' || '+' 중에 있으면 is_negative = 1;
    
    // Read in next the characters until the next non-digit character or the end of the input is reached.
    // The rest of the string is ignored.
    //
    // non-digit char 또는 end of input에 다다를때까지 읽어서 저장해둠
    
    // Convert these digits into an integer (i.e. "123" -> 123, "0032" -> 32).
    // If no digits were read, then the integer is 0. Change the sign as necessary (from step 2).
    //
    int len = strlen(s);
    // integer인 경우 10진수 한자리씩 읽음 (i / power(10, i))
    // for(;len;) {  }
    // [a-z][A-Z] 인 경우 return 0;
    
    // If the integer is out of the 32-bit signed integer range [-231, 231 - 1],
    // then clamp the integer so that it remains in the range.
    // Specifically, integers less than -231 should be clamped to -231, and integers greater than 231 - 1 should be clamped to 231 - 1.
    //
    // if(ret < -231) return -231;
    // else if(ret > 230) return 230;
    
    // Return the integer as the final result.
    return ret;
}

int main()
{
    printf("%d = 42\n", myAtoi("42");
    
    return 0;
}
