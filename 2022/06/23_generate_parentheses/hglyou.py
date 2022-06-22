import unittest
from typing import *

class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        """
        8개의 괄호를 만들 수 있음. 
        각 iter 별로 괄호를 열건지, 닫을건지 선택만 하면서 backtracking 하면 됨. 
        
        Runtime: 39 ms, faster than 84.41% of Python3 online submissions for Generate Parentheses.
        Memory Usage: 14.1 MB, less than 97.81% of Python3 online submissions for Generate Parentheses.
        """
        
        answer = []
        
        def backtrack(stack, opened_brackets, closed_brackets):
            if closed_brackets == n:
                answer.append("".join(stack))
                return
            
            # bracket 열어보기 
            if closed_brackets + opened_brackets < n:
                backtrack(stack + ["("], opened_brackets + 1, closed_brackets)
            
            
            # bracket 닫아보기 
            if opened_brackets > 0:
                backtrack(stack + [")"], opened_brackets - 1, closed_brackets + 1)
        
        backtrack([], 0, 0)

        return answer


class SolutionTest(unittest.TestCase):
    def test(self):
        sol = Solution()
        n = 3
        result = sol.generateParenthesis(n)
        answer = ["((()))","(()())","(())()","()(())","()()()"]
        self.assertEqual(result, answer)


if __name__ == '__main__':
    unittest.main()