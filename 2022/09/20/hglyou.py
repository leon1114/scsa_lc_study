"""
Runtime: 61 ms, faster than 99.80% of Python3 online submissions for Basic Calculator II.
Memory Usage: 15.9 MB, less than 24.73% of Python3 online submissions for Basic Calculator II.
"""

class Solution:
    def calculate(self, s: str) -> int:
        
        # 공백제거
        s = s.replace(' ', '')
        operands = list()
        
        num_str = ''
        num_int = 0
        cur_op = '+'
        
        # 마지막 숫자 / 연산자가 처리되지 않는 edge case 처리를 위한 추가 char
        s += '+'
        
        for ch in s:
            if ch not in ['+', '-', '*', '/']:
                num_str += ch
            else:
                num_int = int(num_str)
                num_str = ''
                
                if cur_op == '+':
                    operands.append(num_int)
                elif cur_op == '-':
                    operands.append(-num_int)
                elif cur_op == '*':
                    op1 = operands.pop()
                    operands.append(op1 * num_int)
                elif cur_op == '/':
                    op1 = operands.pop()
                    operands.append(int(op1 / num_int))
                
                cur_op = ch
        
        return sum(operands)
        
