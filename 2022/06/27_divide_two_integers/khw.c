
/*
Runtime: 0 ms, faster than 100.00% of C online submissions for Divide Two Integers.
Memory Usage: 5.5 MB, less than 52.14% of C online submissions for Divide Two Integers.
*/

#include<stdio.h>

int divide(int dividend, int divisor){
    long long re = 0;
    long long dd = (long long)dividend;
    long long ds = (long long)divisor;
    dd = dd < 0? (long long)(-dd) : (long long)dd;
    ds = ds < 0 ? (long long)(-ds) :(long long)ds;

    long long shift = 1;

    int isPositive = 0;
    if( (dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0)) isPositive = 1;
    
    while(dd >= ds){
        ds = ds <<1;
        shift = shift << 1;
    }
    ds = ds >> 1;
    shift = shift >> 1;

    while(ds)
    {
        if(dd >= ds){
            dd -=ds;
            re += shift;
        }
        ds = ds >> 1;
        shift = shift >> 1;
    }

    if(isPositive==1 && re > 2147483647) re = 2147483647;
    else if (isPositive==0 && re > 2147483648) re = 2147483648;

    
    return (isPositive==1)? re : -re;

}


// int main()
// {
//     printf("%d",divide(-2147483648, -1));

//     return 0;
// }



// int divide(int dividend, int divisor){
//     long long re = (long long)dividend/(long long)divisor;;
//     if(2147483647 < re){
//         re = 2147483647;
//     }
//     if(re < -2147483648) re = -2147483648;

//     return (int)re;
// }

// int divide(int dividend, int divisor){
//     long long re = 0;
//     if (dividend == 0) return re;
//     else if (divisor == 1) return dividend;
//     //else if (dividend == -2147483648 && divisor == -1) return 2147483647;

//     int isPositive = 0;
//     if( (dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0)) isPositive = 1;

//     //존나 런타임 에러나서 음수로 계산
//     long long dd = dividend > 0 ? (long long)(-dividend) : (long long) dividend; 
//     long long ds = divisor > 0 ?  (long long)(-divisor) : (long long) divisor;
    
//     while (dd <= ds)
//     {
//         dd -= ds;
//         re++;
//     }

//     if(isPositive==1 && re > 2147483647) re = 2147483647;
//     else if (isPositive==0 && re > 2147483648) re = 2147483648;

    
//     return (isPositive==1)? re : -re;

// }
