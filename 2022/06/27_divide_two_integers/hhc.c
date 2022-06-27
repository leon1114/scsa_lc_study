// Runtime: 1021 ms, faster than 5.16% of C online submissions for Divide Two Integers.
// Memory Usage: 5.4 MB, less than 72.06% of C online submissions for Divide Two Integers.
// dfs귀찮아서 일단은 통과?


int divide(int dividend, int divisor){
    int u_dend, u_dsor, u_dsor_o;
    int sign = 1;
    int ret = 0;
    
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
    
    
    if(u_dend <= u_dsor_o) {
        ret++;
        u_dend -= u_dsor_o;
    }
    while(u_dend <= u_dsor) {
        ret += ret;
        u_dend -= u_dsor;
        u_dsor += u_dsor;
    }
    while(u_dend <= u_dsor_o) {
        ret++;
        u_dend -= u_dsor_o;
    }
    
    ret = sign?ret:-ret;
    return ret;
}
