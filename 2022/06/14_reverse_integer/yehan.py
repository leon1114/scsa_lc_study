class Solution:
    def reverse(self, x: int) -> int:
        '''
Runtime: 69 ms, faster than 8.48% of Python3 online submissions for Reverse Integer.
Memory Usage: 13.8 MB, less than 61.98% of Python3 online submissions for Reverse Integer.
Use stack to take apart the number and just add it together at the end. really slow though.
'''
        temp = x
        stack = []
        ans = 0
        x = x if x > 0 else -x
        while x:
            stack.append(x % 10)
            x //= 10
        while stack:
            ans *= 10
            ans += stack.pop(0)
        ans = ans if temp > 0 else -ans
        return ans if (-2)**31 <= ans <= 2**31 -1 else 0
