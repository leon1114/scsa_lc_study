#include <stdio.h>
// 다시 dfs 짜서 통과
// Runtime: 0 ms, faster than 100.00% of C online submissions for Divide Two Integers.
// Memory Usage: 5.5 MB, less than 72.06% of C online submissions for Divide Two Integers.
int dfs(int * u_dend, int u_dsor, int ret) {
    int ret_dfs = 0;
    
    if (u_dsor >= -1073741824 && *u_dend <= u_dsor+u_dsor) {
        ret_dfs += dfs(u_dend, u_dsor + u_dsor, ret + ret);
    }
    while(*u_dend <= u_dsor) {
        ret_dfs += ret;
        *(u_dend) -= u_dsor;
    }
    return ret_dfs;
}

int ret;
int divide(int dividend, int divisor){
    int u_dend, u_dsor, u_dsor_o;
    int sign = 1;
    ret = 0;
    
    // get return sign
    if (dividend >= 0) {
        u_dend = -dividend;
        sign = sign;
    } else {
        u_dend = dividend;
        sign = sign ^ 1;
    }
    
    if (divisor >= 0) {
        u_dsor_o = u_dsor = -divisor;
        sign = sign;
    } else {
        u_dsor_o = u_dsor = divisor;
        sign = sign ^ 1;
    }
    
    if (u_dsor == -1) {
        if (!sign) return u_dend;
        else {
            if (dividend == -2147483648) return 2147483647;
            return -u_dend;
        }
    }
    
    if(u_dend <= u_dsor) {
        ret = dfs(&u_dend, u_dsor, 1);
    }
    ret = sign?ret:-ret;
    return ret;
}

int main() {
    // printf("%d\n", divide(-2147483648, -1));
    printf("%d\n", divide(-2147483648, 3));
    // printf("%d\n", divide(-10, 3));
    // printf("%d\n", divide(10, 3));
    // printf("%d\n", divide(55, 2));
    return 0;
}

// // Runtime: 1021 ms, faster than 5.16% of C online submissions for Divide Two Integers.
// // Memory Usage: 5.4 MB, less than 72.06% of C online submissions for Divide Two Integers.
// // dfs귀찮아서 일단은 통과?


// int divide(int dividend, int divisor){
//     int u_dend, u_dsor, u_dsor_o;
//     int sign = 1;
//     int ret = 0;
    
//     // get return sign
//     if (dividend >= 0) {
//         u_dend = -dividend;
//         sign = sign;
//     } else {
//         u_dend = dividend;
//         sign = sign ^ 1;
//     }
    
//     if (divisor >= 0) {
//         u_dsor_o = u_dsor = -divisor;
//         sign = sign;
//     } else {
//         u_dsor_o = u_dsor = divisor;
//         sign = sign ^ 1;
//     }
    
//     if (u_dsor == -1) {
//         if (!sign) return u_dend;
//         else {
//             if (dividend == -2147483648) return 2147483647;
//             return -u_dend;
//         }
//     }
    
    
//     if(u_dend <= u_dsor_o) {
//         ret++;
//         u_dend -= u_dsor_o;
//     }
//     while(u_dend <= u_dsor) {
//         ret += ret;
//         u_dend -= u_dsor;
//         u_dsor += u_dsor;
//     }
//     while(u_dend <= u_dsor_o) {
//         ret++;
//         u_dend -= u_dsor_o;
//     }
    
//     ret = sign?ret:-ret;
//     return ret;
// }
