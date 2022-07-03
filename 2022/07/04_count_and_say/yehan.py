class Solution:
    def dfs(self, n: str):
        '''
        Runtime: 58 ms, faster than 72.26% of Python3 online submissions for Count and Say.
        Memory Usage: 14.1 MB, less than 27.29% of Python3 online submissions for Count and Say.
        use recursion - but its really slow'''
        if n == '1':
            return '1'
        else:
            prev_n = self.dfs(str(int(n)-1)) 
            concatenated_str = ''
            current_digit = None
            current_count = 0
            for digit in prev_n:
                print(f"digit: {digit}")
                if not current_digit:
                    current_digit = digit
                    current_count = 1
                else:
                    if current_digit == digit:
                        current_count += 1
                    else:
                        concatenated_str += (str(current_count) + current_digit)
                        current_digit = digit
                        current_count = 1
            if current_digit:
                concatenated_str += (str(current_count) + current_digit)
            return concatenated_str
        
    def countAndSay(self, n: int) -> str:
        return self.dfs(str(n))
    
