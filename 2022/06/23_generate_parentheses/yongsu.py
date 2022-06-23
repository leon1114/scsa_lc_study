from typing import List
import unittest

# 너무피곤해서 파이썬으로 함

# Runtime: 74 ms, faster than 13.69% of Python3 online submissions for Generate Parentheses.
# Memory Usage: 14.3 MB, less than 12.19% of Python3 online submissions for Generate Parentheses.

class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        ans = []            

        def dfs(element: str, open: int, close: int):
            if open == close == n:
                ans.append(element)
                return

            if open < n:
                next_element = element + '('
                dfs(next_element, open + 1, close)
            if close < open:
                next_element = element + ')'
                dfs(next_element, open, close + 1)
        
        dfs("", 0, 0)
        return ans


class SolutionTests(unittest.TestCase):
    def setUp(self) -> None:
        self.sol = Solution()

    def test_1(self):
        answer = ["((()))","(()())","(())()","()(())","()()()"]
        result = self.sol.generateParenthesis(3)
        self.assertEqual(result, answer)


if __name__ == "__main__":
    unittest.main()