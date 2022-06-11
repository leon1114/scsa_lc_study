class Solution:
    """
    Runtime: 43 ms, faster than 68.96% of Python3 online submissions for String to Integer (atoi).
    Memory Usage: 13.9 MB, less than 29.56% of Python3 online submissions for String to Integer (atoi).

    takeaways: 이런문제 나오면 edge case 찾는데 집중하거나, 솔루션처럼 DFA 를 구현하자.
    https://leetcode.com/problems/string-to-integer-atoi/solution/
    """
    def myAtoi(self, s: str) -> int:
        if s == '':
            return 0
        
        start = 0
        is_negative = False
        
        while s[start] == ' ':
            start += 1
            if start >= len(s):
                break
        
        if start == len(s):
            return 0
        
        if s[start] not in '-+0123456789':
            return 0
        
        if s[start] in '-+':
            if s[start] == '-':
                is_negative = True
            start += 1
        
        if start == len(s):
            return 0
        
        ch = ''
        while s[start] in '0123456789':
            ch += s[start]
            start += 1
            if start >= len(s):
                break
        
        if ch == '':
            return 0
        
        num = int(ch) * (-1 if is_negative else 1)
        
        if num < -2**31:
            return -2**31
        
        if num >= 2**31:
            return 2 ** 31 - 1
        
        return num