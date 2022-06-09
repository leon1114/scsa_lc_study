class Solution:
    '''
    Runtime: 1466 ms, faster than 47.01% of Python3 online submissions for Longest Palindromic Substring.
    Memory Usage: 13.8 MB, less than 90.97% of Python3 online submissions for Longest Palindromic Substring.
    String 한 인덱스 씩 받아서 palindrome 인지 양옆으로 퍼지면서 찾고 최대값을 반환. 브루트 포스 방식
    '''
    def longestPalindrome(self, s: str) -> str:
        ans = ''
        for idx in range(len(s)):
            odd = self.get_palindrome(s, idx, idx)
            even = self.get_palindrome(s, idx, idx+1)
            temp_max = odd if len(odd) > len(even) else even
            if len(temp_max) > len(ans):
                ans = temp_max
        return ans

    def get_palindrome(self, s, lidx, ridx):
        while lidx >= 0 and ridx < len(s) and s[lidx] == s[ridx]:
            lidx -= 1
            ridx += 1
        return s[lidx+1:ridx]

