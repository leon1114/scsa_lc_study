class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        ans = 0
        tmp_ans = 0
        last_duplicate = 0
        word_dict = {} # 문자열이 나왔는지 확인하기 위한 hashmap
        cnt = 0
        for c in s: # 문자열 순회
            if c in word_dict: # 만약 현재 문자가 이미 나왔던 문자라면
                if last_duplicate > word_dict[c][1]: # 만약 마지막으로 중복되었다고 판단한 문자가 현재 문자가 나왔던 적보다 나중이라면 거기부터 다시 시작해야함
                    tmp_ans = cnt - last_duplicate # 현재 위치부터 마지막으로 중복되었다고 판단된 문자까지의 길이를 구함
                else: # 만약 현재 문자가 나왔던 적이 마지막으로 중복되었다고 저장했던 문자보다 이후라면 현재 문자가 나왔던 곳부터 다시 시작해야함
                    tmp_ans = cnt - word_dict[c][1]  # 현재 위치부터 해당 문자가 나왔던 적까지의 길이를 구함
                    last_duplicate = word_dict[c][1] # 그리고 마지막으로 중복되었다고 판단된 문자의 인덱스 갱신
            else: # 만약 새로운 문자라면
                tmp_ans += 1 # 계속 문자열의 길이를 셈
            word_dict[c] = [1, cnt] # 문자열에 1이라고 체크한 후 해당 문자열의 인덱스를 함께 기록
            cnt += 1 # 인덱스를 늘린다
            ans = max(ans, tmp_ans) # 내가 마지막으로 저장한 답 후보와 새로 생긴 답 후보 중 더 긴 값을 return 할거임
        
        return ans


#Runtime: 129 ms, faster than 29.55% of Python3 online submissions for Longest Substring Without Repeating Characters.
#Memory Usage: 14.1 MB, less than 13.70% of Python3 online submissions for Longest Substring Without Repeating Characters.