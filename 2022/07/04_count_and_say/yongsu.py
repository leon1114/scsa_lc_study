# Runtime: 86 ms, faster than 26.43% of Python3 online submissions for Count and Say.
# Memory Usage: 14 MB, less than 54.70% of Python3 online submissions for Count and Say.

# 구현문제

class Solution:
    def countAndSay(self, n: int) -> str:
        ans = '1'
        tmp = '1'

        if n == 1:
            return ans

        for loop in range(1, n):
            ans = tmp
            current_letter = ans[0]
            same_letter_cnt = 1
            tmp = ''
            if ans == '1':
                tmp = '11'
                continue
            for i in range(1, len(ans)):
                if current_letter == ans[i]:
                    same_letter_cnt += 1
                else:
                    tmp += str(same_letter_cnt)
                    tmp += str(current_letter)
                    current_letter = ans[i]
                    same_letter_cnt = 1
                
                if i == len(ans) - 1:
                    tmp += str(same_letter_cnt)
                    tmp += str(current_letter)
                
        ans = tmp
        return ans


sol = Solution()
print(sol.countAndSay(1)) # 1
print(sol.countAndSay(2)) # 11
print(sol.countAndSay(3)) # 21
print(sol.countAndSay(4)) # 1211
