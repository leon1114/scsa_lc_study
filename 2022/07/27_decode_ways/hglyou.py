class Solution:
    def numDecodings(self, s: str) -> int:
        """
        1, 2만 들어온다고치면 피보나치 수열임 
        
        dp[0] = 1
        dp[1] = 1
        dp[2] = 2
        dp[3] = 3
        ... 
        
        input 이 0~9 로 늘어나면 조건부 피보나치 수열임
        
        0 이 가장 까다로우므로 먼저 처리를 해줌
        - 0 이 prefix 로 들어오면 무조건 0 return 
        - s 를 tokenizing -> 0 은 무조건 앞에있는 char 와 조합하여 token 형식으로 저장. 조합이 불가능하다면 (조합했을때 26보다 큼) 바로 0 리턴 
        
        tokenizing 까지 끝나면 이제 조건부 피보나치수열임. 
        
        token 들을 순회하면서, 
        
        앞쪽 token 과 조합이 가능하다면 현재 index 기준 -2 한 위치까지 고려했을때 경우의 수 + -1 위치까지 고려했을때 경우의 수
        조합 불가능 하다면, 현재 index 기준 -1 위치까지 고려했을때 경우의 수를 그대로 받아옴 
        
        Runtime: 33 ms, faster than 93.03% of Python3 online submissions for Decode Ways.
        Memory Usage: 13.8 MB, less than 80.49% of Python3 online submissions for Decode Ways.
        """
        if s[0] == '0':
            return 0
        
        if len(s) == 1:
            return 1
        
        # 먼저 0 을 처리
        tokens = []
        for i in range(len(s) - 1):
            if s[i] == '0':
                if s[i+1] == '0':
                    return 0
                else:
                    continue
            else:
                if s[i+1] == '0':
                    if int(s[i:i+2]) <= 26:
                        tokens.append(s[i:i+2])
                    else:
                        return 0
                else:
                    tokens.append(s[i])
                    
        if s[-1] != '0':
            tokens.append(s[-1])
                
        
        dp = [1, 1] # index 가 아닌 length 기반 
        
        n_2, n_1, n = 1, 1, 1
        
        for i in range(2, len(tokens) + 1):
            c = tokens[i-1]
            
            if int(tokens[i-2] + c) <= 26:
                n = n_2 + n_1
            else:
                n = n_1
            
            n_2, n_1 = n_1, n
        
        return n
            
