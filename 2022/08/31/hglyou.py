"""
Runtime: 71 ms, faster than 6.96% of Python3 online submissions for Fraction to Recurring Decimal.
Memory Usage: 14 MB, less than 70.22% of Python3 online submissions for Fraction to Recurring Decimal.
"""

class Solution:
    def fractionToDecimal(self, numerator: int, denominator: int) -> str:
        if numerator == 0:
            return "0"
        
        tokens = list()
        
        if (numerator < 0) ^ (denominator < 0):
            tokens.append('-')
            
        numerator = abs(numerator)
        denominator = abs(denominator)
        
        tokens.append(str(numerator // denominator))
        remainder = numerator % denominator
        
        if not remainder:
            return ''.join(tokens)
        
        tokens.append('.')
        
        remainders_position = dict()
        
        while remainder:
            if remainder in remainders_position:
                tokens.insert(remainders_position[remainder], "(")
                tokens.append(")")
                break
            
            remainders_position[remainder] = len(tokens)
            remainder *= 10
            tokens.append(str(remainder // denominator))
            remainder = remainder % denominator
        
        return ''.join(tokens)
