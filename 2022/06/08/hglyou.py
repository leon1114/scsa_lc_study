class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        if len(s) == 0:
            return 0
        
        is_taken = set([s[0]])
        start = 0
        end = 1 # exclusive
        max_len = 1
        
        while end < len(s):
            
            while s[end] in is_taken:
                is_taken.remove(s[start])
                start += 1
            is_taken.add(s[end])
            end += 1
            
            _len = end - start
            max_len = max(max_len, _len)
            
        return max_len
