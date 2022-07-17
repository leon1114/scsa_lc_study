class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        answer = []
        
        def bt(idx, tmp_result):
            if idx == len(nums):
                answer.append(tmp_result)
                return
            
            bt(idx + 1, tmp_result)
            bt(idx + 1, tmp_result + [nums[idx]])
        
        bt(0, [])
        return answer
