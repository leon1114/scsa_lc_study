class Solution:
    def divide(self, dividend: int, divisor: int) -> int:
        """
        Runtime: 47 ms, faster than 61.88% of Python3 online submissions for Divide Two Integers.
        Memory Usage: 13.9 MB, less than 25.75% of Python3 online submissions for Divide Two Integers.
        """
        is_negative = False
        
        if dividend < 0 and divisor > 0:
            is_negative = True
            
        if dividend > 0 and divisor < 0:
            is_negative = True
            
        dividend, divisor = abs(dividend), abs(divisor)
            
        mul = 0 # 몇번 2를 곱했는지 count 
        cnt = 0 # 몇번 divisor 만큼 더했는지 count 
        
        while divisor << mul < dividend:
            mul += 1
        
        if divisor == dividend:
            cnt =  1 << mul if not is_negative else -(1 << mul)
        else:
            while True:
                if divisor << mul <= dividend:
                    dividend -= divisor << mul
                    cnt += 1 << mul
                else:
                    mul -= 1

                if dividend < divisor:
                    break
        
            cnt = cnt if not is_negative else -cnt
            
        cnt = min(cnt, (1 << 31) - 1)
        cnt = max(cnt, -(1 << 31))
        return cnt
            