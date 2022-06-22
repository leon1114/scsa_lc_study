class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        '''
        Runtime: 59 ms, faster than 35.09% of Python3 online submissions for Generate Parentheses.
        Memory Usage: 14.3 MB, less than 39.20% of Python3 online submissions for Generate
        '''
        ans = []
        def dfs(parenthesis, to_open, to_close): 
            if len(parenthesis) == n * 2:
                ans.append(parenthesis)
            
            if to_open > 0:
                dfs(parenthesis + '(', to_open - 1, to_close + 1)
            
            if to_close > 0:
                dfs(parenthesis + ')', to_open, to_close - 1)
        
        dfs('', n, 0)
        return ans
