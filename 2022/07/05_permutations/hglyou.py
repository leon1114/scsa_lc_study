from typing import *

class Solution:
    """
    Runtime: 56 ms, faster than 60.67% of Python3 online submissions for Permutations.
    Memory Usage: 14.2 MB, less than 21.90% of Python3 online submissions for Permutations.
    """
    def permute(self, nums: List[int]) -> List[List[int]]:
        answer = []
        def get_permutation(wip, candidates):
            if len(wip) == len(nums):
                answer.append(wip)
                
            for i, num in enumerate(candidates):
                if num == -99:
                    continue
                candidates[i] = -99
                get_permutation(wip + [num], candidates)
                candidates[i] = num
                
        get_permutation([], nums)
        return answer
            
            