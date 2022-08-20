"""
Runtime: 65  ms, faster than 63.35% of Python3 online submissions for Word Break.
Memory Usage: 14.3 MB, less than 14.31% of Python3 online submissions for Word Break.
"""

class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        
        word_set = set(wordDict)
        
        # python 의 함수 output 캐싱해주는 lru_cache magic 사용해 memoization 
        @lru_cache
        def bt(_s) -> bool:
            if _s == "":
                return True
            
            for i in range(len(_s) + 1):
                if _s[:i] in word_set:
                    res = bt(_s[i:])
                    if res:
                        return res

            return False
                
        return bt(s)
