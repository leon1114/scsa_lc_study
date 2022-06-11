class Solution:
    def expandAroundCenter(self, s: str, start: int, end: int) -> str:
        """
        O(n^2) solution

        start, end 로 부터 양쪽으로 뻗어나가며 가장 긴 palinedromic string 을 반환
        못 찾을 경우 빈 문자열 반환

        호출하는 쪽에서 s[start: end+1] 은 palindromic 함을 확인하고 호출 해야 함.

        start: start index (inclusive)
        end: start index (inclusive)

        returns: 가장 긴 palinedromic substring 을 반환

        Runtime: 660 ms, faster than 91.82% of Python3 online submissions for Longest Palindromic Substring.
        Memory Usage: 13.9 MB, less than 90.84% of Python3 online submissions for Longest Palindromic Substring.
        """

        s_len = len(s)

        while start >= 0 and end < s_len and s[start] == s[end]:
            start -= 1
            end += 1

        return s[start + 1:end]

    def longestPalindrome(self, s: str) -> str:
        max_len = 0
        max_str = ""

        for idx in range(len(s)):                               # iter n times
            candidate = self.expandAroundCenter(s, idx, idx)    # O(n) operation
            if len(candidate) > max_len:
                max_len = len(candidate)
                max_str = candidate

            if idx + 1 < len(s) and s[idx] == s[idx + 1]:
                # palinedrome 의 center 가 두 character 사이에 있을 경우를 위함. i.e) abba
                candidate = self.expandAroundCenter(s, idx, idx + 1)
                if len(candidate) > max_len:
                    max_len = len(candidate)
                    max_str = candidate

        return max_str


