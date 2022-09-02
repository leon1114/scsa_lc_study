"""
Runtime: 4287 ms, faster than 12.33% of Python3 online submissions for Factorial Trailing Zeroes.
Memory Usage: 13.9 MB, less than 21.75% of Python3 online submissions for Factorial Trailing Zeroes.

일단 follow up 조건인 log 시간 복잡도는 충족 안시킴
"""

class BruteForceSolution:
    def trailingZeroes(self, n: int) -> int:
        if n == 0 :
            return 0
        
        fac = 1
        
        for i in range(1, n+1):
            fac *= i
        
        fac = str(fac)
        fac_len = len(fac)
        
        return fac_len - len(fac.rstrip('0'))
        
        
"""
Runtime: 28 ms, faster than 98.47% of Python3 online submissions for Factorial Trailing Zeroes.
Memory Usage: 13.8 MB, less than 97.03% of Python3 online submissions for Factorial Trailing Zeroes.
"""

class Solution:
    def trailingZeroes(self, n: int) -> int:
        if n == 0 :
            return 0
        
        """
        trailing zeroes -> factor 들에서 2, 5 pair 의 수를 찾으면 됨. 
        단, 2 의 갯수는 항상 5의 갯수보다 많으므로 5의 갯수만 빠르게 잘 찾으면 됨. 
        """
        
        cnt = 0
        
        deno = 5
        
        """
        --> 
        n 까지의 누적곱에서 5의 배수인 인수 갯수 구하기
        아주 간단히 구하고자 한다면.. 
        
        5 로 나누어 떨어지는 숫자 갯수 구하기 
        cnt = 0
        for i in range(n+1):
            if i % 5 == 0:
                cnt += 1
        
        단, 이렇게 하면 25 같이 5가 2개 들어있는 숫자에서 5의 갯수를 적게 카운트하게 된다. 
        따라서, 
        
        25로 나누어 떨어지는 숫자 갯수 구하기 ...
        125로 나누어 떨어지는 숫자 갯수 구하기 ... 
        
        위와 같이 반복하여 총 갯수를 세어야 한다. 
        
        이 동작 (1~n 까지의 숫자중 특정 5의 배수로 나누어 떨어지는 숫자의 갯수 구하기) 하나하나를 살펴보면
        그냥 나눗셈해서 몫을 취하는 과정임. 
        
        5로 나누어 떨어지는 숫자 갯수 구하기 -> n // 5
        25 ... -> n // 25
        125 ... -> n // 125 
        
        -> log_5(n) 만큼 나눗셈 하면 되므로 시간 복잡도가 O(logn) 이 된다. 
        
        """
        
        while deno <= n:
            cnt += n // deno
            deno *= 5
        
        return cnt
