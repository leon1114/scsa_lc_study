import unittest
from typing import *

class Solution:
    def countAndSay(self, n: int) -> str:
        """
        Runtime: 55 ms, faster than 78.42% of Python3 online submissions for Count and Say.
        Memory Usage: 13.9 MB, less than 85.96% of Python3 online submissions for Count and Say.
        """
        ans = ["1",]
        
        if n == 1:
            return ans[0]
        
        for i in range(1, n):
            prv_str = ans[i-1]
            
            _ans = ""
            
            cur_num = None
            cur_num_cnt = 1
            for j, num in enumerate(prv_str):
                if cur_num is None:
                    cur_num = prv_str[j]
                    cur_num_cnt = 1
                else:    
                    if num == cur_num:
                        cur_num_cnt += 1
                    else:
                        _ans += f'{cur_num_cnt}{cur_num}'
                        cur_num = prv_str[j]
                        cur_num_cnt = 1
            _ans += f'{cur_num_cnt}{cur_num}'
            
            ans.append(_ans)
        
        return ans[-1]


class SolutionTests(unittest.TestCase):
    def test_example(self):
        self.assertEqual("1211", Solution().countAndSay(4))


if __name__ == '__main__':
    unittest.main()