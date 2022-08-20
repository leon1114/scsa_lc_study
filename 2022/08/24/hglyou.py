"""
Runtime: 67 ms, faster than 95.62% of Python3 online submissions for Evaluate Reverse Polish Notation.
Memory Usage: 14.4 MB, less than 21.66% of Python3 online submissions for Evaluate Reverse Polish Notation.
"""

class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        """
        token 을 iterate 하면서, 
        피연산자는 스택에 쌓음 
        연산자가 나오면 스택에서 두개 꺼내서 연산 후 다시 스택에 넣음 
        """
        
        operands = list()
        operators = {
            '+': int.__add__,
            '-': int.__sub__,
            '*': int.__mul__,
            '/': int.__truediv__
        }
        
        for token in tokens:
            if token in operators:
                op2 = operands.pop()
                op1 = operands.pop()
                operator = operators[token]
                op3 = operator(op1, op2)
                
                # operator 가 float 인 경우 int 로 변환해서 넣어주기 위해 캐스팅 
                operands.append(int(op3))
            else:
                operands.append(int(token))
        
        return operands.pop()
        
