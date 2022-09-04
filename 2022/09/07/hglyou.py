"""
Runtime: 5453 ms, faster than 46.12% of Python3 online submissions for Count Primes.
Memory Usage: 52.7 MB, less than 82.03% of Python3 online submissions for Count Primes.
"""

class Solution:
    def countPrimes(self, n: int) -> int:
        if n <= 2:
            return 0
        
        isPrime = [True] * n
        isPrime[0] = False
        isPrime[1] = False
        
        for i in range(2, n):
            if isPrime[i]:
                for num in range(i * 2, n, i):
                    isPrime[num] = False
                    
        return sum(isPrime)
