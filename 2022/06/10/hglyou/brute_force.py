class Solution:
    def longestPalindrome(self, s: str) -> str:
        """
        Bruteforce solution + early stops 
        
        어차피 s 의 length 가 max 1000 이므로, n^3 solution 으로 풀어도 상관 없음...?

        Runtime: 2650 ms, faster than 24.14% of Python3 online submissions for Longest Palindromic Substring.
        Memory Usage: 13.8 MB, less than 90.97% of Python3 online submissions for Longest Palindromic Substring.
        """
        
        max_len = 1
        max_str = s[0]
        
        for start in range(len(s)):                 # iter n times
            if len(s) - start <= max_len:
                break
            for end in range(len(s), start, -1):    # iter n itmes
                if end - start <= max_len:
                    break
                if s[start] != s[end-1]:
                    continue
                substr = s[start: end]
                if substr == substr[::-1]:          # 간단해보이지만 O(n) 임.
                    if end - start > max_len:
                        max_len = end - start
                        max_str = substr
                        
        return max_str
        
        
        