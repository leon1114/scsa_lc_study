
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
        
        Runtime: 429 ms, faster than 16.91% of Python3 online submissions for Minimum Window Substring.
        Memory Usage: 14.8 MB, less than 10.33% of Python3 online submissions for Minimum Window Substring.
        
        time complexity 는 two pointer 이고, pointer 이동할 때 마다 constant 니까 O(n) 인 것 같은데 매우느림 
        - O(n) 이 아닌가?
        - O(n) 인데 constant 부분이 너무 오래걸리나? 
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
        
        # check 내부에서는 최대 loop 를 52번 도니까 엄밀히 따지면 constant time complexity 임. 
        def check():
            for k, v in t_cnt.items():
                if sub_cnt[k] < v:
                    return False
            return True
        
        checked = check()
        
        while ed < len(s):
            if checked:
                if len(s[st:ed+1]) < len(answer) or answer == "":
                    answer = s[st:ed+1]
                
                if s[st] in t_cnt and sub_cnt[s[st]] - 1 < t_cnt[s[st]]:
                    checked = False
                
                sub_cnt[s[st]] -=1
                st += 1
            else:
                if ed + 1 < len(s):
                    ed_c = s[ed + 1]
                    sub_cnt[ed_c] += 1
                    
                    if sub_cnt[ed_c] >= t_cnt[ed_c] and check():
                        checked = True
                ed += 1
                
        
        return answer
            
