import unittest
from typing import *

class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        """
        s 로 들어온 스트링을 p 로 들어온 패턴이 전부 커버할 수 있는지 확인하는 함수. 

        s 는 알파벳 소문자로만 이루어져 있고,
        p 는 알파벳 소문자 + ., * 로 이루어져있다. 

        . = 어떤 알바벳 소문자든 매칭 됨
        * = 바로 앞에 위치한 문자가 0번 또는 다수번 매칭 됨. 

        전형적인 DP 문제임. (Optimal structure, overwrapping subproblems)

        dp table 정의 
        dp[p_i, s_i] -> patern[:p_i] 로 string[:s_i] 까지 매칭이 된다는 의미 

        recurence 관계 정의 
        - pattern character 가 소문자일 경우 -> dp[p_i][s_i] = dp[p_i][s_i] and p_ch == s_ch 
        - pattern character 가 . 일 경우 -> dp[p_i][s_i] = dp[p_i][s_i]
        - pattern character 가 * 일 경우
            - 이전 패턴이 s_i 까지 매칭했을 경우, * 패턴이 0 번 나오는 케이스 이용해 동일한 index (s_i) 까지 커버할 수 있음. 
            - 바로 전 s_i 까지 매칭되었거나 dp[p_i-1][s_i-1] 일 경우 * 앞에 있는 character 와 s_ch 가 동일하다면 커버할 수 있음. 


        정답 
        dp[len(p_i), len(s_i)]
        """
        # pattern 정리
        pattern = []
        for idx, ch in enumerate(p):
            if idx + 1 < len(p) and p[idx + 1] == '*':
                pattern.append(p[idx:idx+2])
            else:
                if ch != '*':
                    pattern.append(ch)
        p = pattern

        dp = [[False for _ in range(len(s) + 1)] for _ in range(len(p) + 1)]
        
        # base case 설정 
        dp[0][0] = True
        for p_i in range(1, len(dp)):
            for s_i in range(1, len(dp[0])):
                p_ch = p[p_i - 1]
                s_ch = s[s_i - 1]

                if '*' in p_ch:
                    p_ch_target = p_ch[0]

                    if s_i == 1:
                        dp[p_i][0] = dp[p_i-1][0]
                    dp[p_i][s_i] = dp[p_i - 1][s_i] or ((dp[p_i-1][s_i-1] or dp[p_i][s_i-1]) and (p_ch_target == s_ch or p_ch_target == '.'))
                else:
                    if p_ch == '.':
                        dp[p_i][s_i] = dp[p_i - 1][s_i - 1]
                    else:
                        dp[p_i][s_i] = dp[p_i - 1][s_i - 1] and p_ch == s_ch
        
        return dp[len(p)][len(s)]


class SolutionTests(unittest.TestCase):
    def setUp(self) -> None:
        self.sol = Solution()

    def test_1(self):
        s = 'aab'
        p = 'c*a*b'
        answer = True
        result = self.sol.isMatch(s, p)
        self.assertEqual(result, answer)

    def test_2(self):
        s = "mississippi"
        p = "mis*is*ip*."
        answer = True
        result = self.sol.isMatch(s, p)
        self.assertEqual(result, answer)

    
    def test_3(self):
        s = "mississippi"
        p = "mis*is*ip*"
        answer = False
        result = self.sol.isMatch(s, p)
        self.assertEqual(result, answer)

    def test_4(self):
        s = "aaa"
        p = "ab*a*c*a"
        answer = True
        result = self.sol.isMatch(s, p)
        self.assertEqual(result, answer)

    def test_5(self):
        s = "aaca"
        p = "ab*a*c*a"
        answer = True
        result = self.sol.isMatch(s, p)
        self.assertEqual(result, answer)

    def test_6(self):
        s = "mississippi"
        p = "mis*is*p*."
        answer = False
        result = self.sol.isMatch(s, p)
        self.assertEqual(result, answer) 

    def test_7(self):
        s = "a"
        p = "ab*"
        answer = True
        result = self.sol.isMatch(s, p)
        self.assertEqual(result, answer)  

    def test_8(self):
        s = 'abcd'
        p = 'd*'
        answer = False
        result = self.sol.isMatch(s, p)
        self.assertEqual(result, answer)  

    def test_9(self):
        s = "aaabaaaababcbccbaab"
        p = "c*c*.*c*a*..*c*"
        answer = True
        result = self.sol.isMatch(s, p)
        self.assertEqual(result, answer)  

if __name__ == '__main__':
    unittest.main()