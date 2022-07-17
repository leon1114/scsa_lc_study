
from collections import defaultdict

class Solution:
    def minWindow(self, s: str, t: str) -> str:
        """
        Thoughts
        
        two pointer approach? 
        
        s, e (both inclusive)
        초기값 start = 0, end = 1 (exclusive)
        
        substring = s[start:end]
        
        substring 이 T 를 포함하지 않을 경우 e 를 계속 늘려나감 
        
        T 를 포함하게되면 s 를 계속 좁힘 
        
        다시 T 를 포함하지 않게되면 e 를 늘려나감 
        
        이러다가 e 가 마지막에 도달하면 종료 
        
        일단 O(m+n) 은 follow up 이니까 ... 
        Runtime: 677 ms, faster than 8.50% of Python3 online submissions for Minimum Window Substring.
        Memory Usage: 14.6 MB, less than 82.83% of Python3 online submissions for Minimum Window Substring.
        """
        
        # base case 
        
        if s == t:
            return s
        
        if len(t) > len(s):
            return ""
        
        # target count 생성
        t_cnt = defaultdict(int)
        for c in t:
            t_cnt[c] += 1
            
        # substring count 선언
        sub_cnt = defaultdict(int)
        st, ed = 0, 0
        sub_cnt[s[st]] += 1
        
        answer = ""
        
        def check():
            for k, v in t_cnt.items():
                if sub_cnt[k] < v:
                    return False
            return True
                
        
        while ed < len(s):
            if check():
                if len(s[st:ed+1]) < len(answer) or answer == "":
                    answer = s[st:ed+1]
                    
                sub_cnt[s[st]] -=1
                st += 1
            else:
                if ed + 1 < len(s):
                    ed_c = s[ed + 1]
                    sub_cnt[ed_c] += 1
                ed += 1
                
        
        return answer
            
