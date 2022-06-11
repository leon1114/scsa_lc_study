class Solution:
    def reverse(self, x: int) -> int:
        is_negative = '-' in str(x)
        
        if is_negative:
            x_str = str(x)[1:]
        else:
            x_str = str(x)
        
        x_str = x_str[::-1]
        x = int(x_str) * (-1 if is_negative else 1)
        
        if not (-2**31 <= x <= 2**31 - 1):
            return 0
        else:
            return x