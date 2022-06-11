class Solution:
    """
    f(i,j) => s[i:j-1] 가 palinedrome 인지 판단

    f(i,j) => f(i+1,j-1) | s[i] == s[j-1]
    """
    is_palindrome = dict()

    def checkIsPalindrome(self, s, start, end):
        if start == end:
            self.is_palindrome[(start, end)] = True
            return True

        if start + 1 == end:
            if s[start] == s[end]:
                self.is_palindrome[(start, end)] = True
                return True
            else:
                self.is_palindrome[(start, end)] = False
                return False

        if s[start] != s[end]:
            self.is_palindrome[(start, end)] = False
            return False

        if (start+1, end-1) in self.is_palindrome:
            if self.is_palindrome[start+1,end-1]:
                self.is_palindrome[(start, end)] = True
                return True
            else:
                self.is_palindrome[(start, end)] = False
                return False
        else:
            if self.checkIsPalindrome(s, start + 1, end - 1):
                self.is_palindrome[(start, end)] = True
                return True
            else:
                self.is_palindrome[(start, end)] = False
                return False



    def longestPalindrome(self, s: str) -> str:
        max_len = 0
        max_str = ""
        for i in range(len(s)):
            for j in range(len(s)):
                if j - i + 1 < max_len:
                    continue
                if self.checkIsPalindrome(s, i, j):
                    if j - i + 1 > max_len:
                        max_len = j - i + 1
                        max_str = s[i:j+1]

        return max_str


