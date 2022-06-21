from typing import List
import unittest

# Runtime: 64 ms, faster than 7.91% of Python3 online submissions for Letter Combinations of a Phone Number.
# Memory Usage: 13.9 MB, less than 29.76% of Python3 online submissions for Letter Combinations of a Phone Number.

# C로 짜기 연습하자 제발

class Solution:
    letters = {}

    def __init__(self) -> None:
        self.letters[2] = "abc"
        self.letters[3] = "def"
        self.letters[4] = "ghi"
        self.letters[5] = "jkl"
        self.letters[6] = "mno"
        self.letters[7] = "pqrs"
        self.letters[8] = "tuv"
        self.letters[9] = "wxyz"

    # 전부 다 순회하면서 하나씩 붙이기
    def letterCombinations(self, digits: str) -> List[str]:
        ans = []

        def dfs(index: int, buf: str, leftover: str):
            if len(buf) >= len(digits):
                ans.append(buf)
                return
            
            for i in range(len(leftover)):                  # 전체 숫자를 다 돌면서 할거임
                for j in self.letters[int(leftover[i])]:    # 그 숫자부터 시작해서 나머지 숫자들로 만들 수 있는 조합을 만들기
                    dfs(i + 1, buf + j, leftover[i + 1:])   # 현재 보고 있는 숫자 이전은 다시 조합할 필요 없으므로 내가 보려는 숫자는 그 숫자들 이전은 모두 제외한 숫자만 봐야함

        if len(digits) == 0:
            return []

        dfs(0, "", digits)

        return ans

class SolutionTests(unittest.TestCase):
    def setUp(self) -> None:
        self.sol = Solution()

    def test_1(self):
        answer = ["ad","ae","af","bd","be","bf","cd","ce","cf"]
        result = self.sol.letterCombinations("23")
        self.assertEqual(result, answer)


if __name__ == "__main__":
    unittest.main()