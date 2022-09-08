//Runtime: 133 ms, faster than 99.00% of C++ online submissions for Count Primes.
//Memory Usage: 11.3 MB, less than 24.92% of C++ online submissions for Count Primes.
//???의 채 적용하고 (바깥쪽 for문) 합성수는 건너뛰는 방법으로 (check[i] == 1 continue, j += i) 최대한 성능 높여봄..

class Solution {
    char check[5000001];
public:
    int countPrimes(int n) {
        if (n < 3) return 0;
        memset(check, 0, sizeof(char) * n);

        int rt = sqrt(n);
        for (int i = 3; i <= rt; i += 2) {
            if (check[i] == 1) continue;
            for (int j = i + i; j < n; j += i) {
                check[j] = 1;
            }
        }
        int sol = 1;
        for (int i = 3; i < n; i += 2) {
            if (check[i] == 0)
                sol++;
        }
        return sol;
    }
};
