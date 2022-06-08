# 파이썬 배우는데 의의를 둔다. ㅅㅂ ㅈㄴ 힘드네
# Runtime: 862 ms, faster than 8.98% of Python3 online submissions for Longest Substring Without Repeating Characters.
# Memory Usage: 14 MB, less than 49.30% of Python3 online submissions for Longest Substring Without Repeating Characters.

class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        maxCount = 0
        dCharCount = dict()
        for i in s : 
            if i in dCharCount:
                # if dCharCount[i] > maxCount:
                #     maxCount = dCharCount[i]
                li = []
                for key in dCharCount:
                    if dCharCount[key] > maxCount:
                        maxCount = dCharCount[key]
                    if dCharCount[key] > dCharCount[i]:
                        li.append(key)
                for l in li:
                    del dCharCount[l]
                dCharCount[i] = 0
            else:
                dCharCount[i] = 0
            for key in dCharCount:
                dCharCount[key] += 1



        for key in dCharCount:
            if dCharCount[key] > maxCount:
                maxCount = dCharCount[key]

        return maxCount
