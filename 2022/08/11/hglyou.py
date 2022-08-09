class Solution:
    """
    Runtime: 707 ms, faster than 87.30% of Python3 online submissions for Palindrome Partitioning.
    Memory Usage: 30.4 MB, less than 43.41% of Python3 online submissions for Palindrome Partitioning.
    """
    def partition(self, s: str) -> List[List[str]]:
        """
        backtracking 
        
        """
        
        ans = list()
        def bt(_s, temp_arr=None):
            if temp_arr is None:
                temp_arr = list()
                
            if _s == "":
                ans.append(list(temp_arr))
                return
            
            for j in range(1, len(_s)+1):
                sub_str = _s[:j]
                if sub_str == sub_str[::-1]:
                    temp_arr.append(sub_str)
                    bt(_s[j:], temp_arr)
                    temp_arr.pop()

        bt(s, None)
        
        return ans
                
            
