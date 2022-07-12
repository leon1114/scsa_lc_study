//Runtime: 4 ms, faster than 32.00% of C++ online submissions for Pow(x, n).
//Memory Usage: 5.9 MB, less than 43.34% of C++ online submissions for Pow(x, n).
//n이 음수인경우도 있어서 조건이 좀 추가되긴 하지만 
//x^n = x^(n/2) * x^(n/2) 인 걸 이용함.(n이 홀수라면 *x추가)
//이렇게 하면 주어진 조건(n ~ 2^31) 에 대해 2^31번 곱할 필요 없이 log2(31) 약 8회 재귀로 풀 수 있음


class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1;
        else if (n == 1) return x;
        else if (n == -1) return 1/x;
        double ret = myPow(x, n/2);
        if (n % 2 == 0) 
            return ret*ret;
        else
            return ret*ret*((n > 0)?x:1/x);    
    }
};
