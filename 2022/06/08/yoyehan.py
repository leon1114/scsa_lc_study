class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        ans = left = 0
        dic = {}
        for right, c in enumerate(s):
            if c in dic and left <= dic[c] + 1:
                cur_len = right - left
                ans = cur_len if cur_len > ans else ans
                left = dic[c] + 1

            dic[c] = right
            # print(c, left, right, ans, dic)
        last_len = len(s) - left
        return ans if ans > last_len else last_len
