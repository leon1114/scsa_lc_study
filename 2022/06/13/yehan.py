class Solution:
    def convert(self, s: str, numRows: int) -> str:
        '''
        Runtime: 99 ms, faster than 38.12% of Python3 online submissions for Zigzag Conversion.
Memory Usage: 14.2 MB, less than 28.89% of Python3 online submissions for Zigzag Conversion.
각 지그재그의 가로줄을 미리 설정하고 윗단과 아랫단을 만날떄마다 방향을 바꿔 스트링에 적재함. 끝나면 조인해서 출력'''
        if numRows == 1 or numRows >= len(s):
            return s
        
        rows = [''] * numRows
        idx = 0
        step = 1
        
        for c in s:
            print(c, idx)
            rows[idx] += c
            
            if idx == 0: 
                step = 1
            elif idx == (numRows - 1):
                step = -1 
                
            idx += step
            
        return ''.join(rows)
