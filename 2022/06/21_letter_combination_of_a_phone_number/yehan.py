class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        '''
        Runtime: 53 ms, faster than 26.17% of Python3 online submissions for Letter Combinations of a Phone Number.
        Memory Usage: 13.9 MB, less than 77.92% of Python3 online submissions for Letter Combinations of a Phone Number.  
        '''
        ans = []
        mapping = {'2': 'abc', '3': 'def', '4': 'ghi', '5': 'jkl', 
                   '6': 'mno', '7': 'pqrs', '8': 'tuv', '9': 'wxyz'}
        
        def dfs(word, number):
            if not number:
                ans.append(word)
                return
            else:
                letter_combo = mapping[number[0]]
                for letter in letter_combo:
                    dfs(word + letter, number[1:])
        if digits:
            dfs('', digits)
        return ans
