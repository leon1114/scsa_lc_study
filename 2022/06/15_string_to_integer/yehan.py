class Solution:
    def myAtoi(self, str: str) -> int:
        '''
Runtime: 47 ms, faster than 58.63% of Python3 online submissions for String to Integer (atoi).
Memory Usage: 13.9 MB, less than 29.44% of Python3 online submissions for String to Integer (atoi).
그냥 구현하면 통과됨
        '''
        ans = 0
        sign  = 0
        startidx = 0
        if not str:
            return 0 
        
        for i, c in enumerate(str):
            if c == ' ':
                pass
            else:
                startidx = i
                break
        
        if str[startidx] == '-':
            sign = -1
            startidx += 1
        elif str[startidx] == '+':
            sign = 1
            startidx += 1
        for i in range(startidx, len(str)):
            c = str[i]
            if '0' <= c <= '9':
                ans *= 10
                ans += int(c)
            else:
                break
                
        if sign < 0:
            if -ans < -2**31:
                ans = 2**31
            return -ans
        else:
            if ans > 2**31 - 1:
                ans = 2**31 -1
        return ans
