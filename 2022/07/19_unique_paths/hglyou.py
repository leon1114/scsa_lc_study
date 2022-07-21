class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        """
        
        스스로 푼 솔루션
        
        time, space complexity O(nm), O(n)
        
        path_cnts[r][c] = path_cnts[r-1][c] + path_cnts[r][c-1]
        
        Runtime: 33 ms, faster than 91.41% of Python3 online submissions for Unique Paths.
        Memory Usage: 13.9 MB, less than 73.29% of Python3 online submissions for Unique Paths.
        """
        
        if m == 1 or n == 1:
            return 1
    
        
        path_cnts = [1] * n
        
        for r in range(1, m):
            for c in range(n):
                left_cnt = 0 if c == 0 else path_cnts[c - 1]
                path_cnts[c] += left_cnt
                
        return path_cnts[-1]
    
    
    def uniquePathsCombinatorial(self, m: int, n: int) -> int:
        """
        
        다른 사람 풀이 기록용으로 남기기
        
        time, space complexity O((M+N)(log(M+N)loglog(M+N))^2), O(1)
        
        Runtime: 37 ms, faster than 82.78% of Python3 online submissions for Unique Paths.
        Memory Usage: 14 MB, less than 14.86% of Python3 online submissions for Unique Paths.
        
        time complexity 는 더 낫긴한데, 실 수행시간이 딱히 더 나아지진 않음. input이 작아서 그런듯 함 
        
        풀이 설명? 
        
        결국 목적지로 가려면 오른쪽으로 m - 1번, 아래쪽으로 n - 1 번 움직여야 함. 
        
        움직이는 횟수는 정해져있고, 몇번째 move 에서 오른쪽 (또는 아래쪽) 으로 움직일지 정하면 됨. 
        
        총 이동 횟수 -> m + n - 2
        
        총 이동 횟수에서 몇 번째 move 에서 아래쪽으로 움직일지 정하면 됨.
        그 경우의 수 구하기 >> 총 이동 횟수 C (m-1)
        
        >> (m + n - 2)! / (m - 1)! / (m + n - 2 - (m - 1))! >> (m + n -2)! / (m - 1)! / (n - 1)!
        
        """
        
        from math import factorial
        
        return factorial(m + n - 2) // factorial (n - 1) // factorial (m - 1)
