class Solution:
    def divide(self, dividend: int, divisor: int) -> int:
# Brute Force
#         positive = True
#         if dividend < 0:
#             positive = False
#         if divisor < 0:
#             if not positive:
#                 positive = True
#             else:
#                 positive = False
        
#         dividend = abs(dividend)
#         divisor = abs(divisor)
#         ans = 0
#         while dividend >= divisor:
#             dividend -= divisor
#             ans += 1
            
#         if positive:
#             return ans
#         else:
#             return -ans
        '''
        Runtime: 38 ms, faster than 85.19% of Python3 online submissions for Divide Two Integers.
        Memory Usage: 14 MB, less than 25.71% of Python3 online submissions for Divide Two Integers.'''
        ans = 0
        if ((dividend < 0) and (divisor < 0)) or ((dividend > 0) and (divisor > 0)): 
            positive = True
        else:
            positive = False
        
        dividend = abs(dividend)
        divisor = abs(divisor)
        
        while dividend >= divisor:
            
            temp_divisor = divisor
            i = 1
            
            while dividend >= (temp_divisor << 1):
                temp_divisor <<= 1
                i <<= 1
            
            dividend -= temp_divisor
            ans += i
            
            
        
        if positive:
            return min(ans, 2**31 -1)
        else:
            return max(-ans, -2**31)
        
