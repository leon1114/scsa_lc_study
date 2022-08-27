"""
Runtime: 43 ms, faster than 62.60% of Python3 online submissions for Word Break II.
Memory Usage: 13.9 MB, less than 82.08% of Python3 online submissions for Word Break II.
"""
class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        """
        back tracking 문제임 
        """
        word_set = set(wordDict)
        
        ans = []
        tmp = []
        
        def bt(_s) -> bool:
            if _s == "":
                res = " ".join(tmp)
                ans.append(res)
                return
            
            for word in wordDict:
                if _s[:len(word)] == word:
                    tmp.append(word)
                    bt(_s[len(word):])
                    tmp.pop()
            
        bt(s)
        
        return ans
