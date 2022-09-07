// Runtime: 410 ms, faster than 20.05% of C online submissions for Count Primes.
// Memory Usage: 24.9 MB, less than 60.45% of C online submissions for Count Primes.

int countPrimes(int n){
    if (n <= 2) return 0;
    int primes[5000005] = {1, };
    int cnt = 1;
    for (int i = 3; i < n; i += 2) {
        if (!primes[i]) {
            cnt++;
            for (int j = i; j < n; j+=i) {
                primes[j] = 1;
            }
        }
    }
    return cnt;
}
