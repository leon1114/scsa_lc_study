class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        """
        각 숫자를 선택한 경우, 선택하지 않은경우로 나눠서 백트랙킹
        """
        answer = []
        
        def bt(idx, tmp_result):
            if idx == len(nums):
                answer.append(tmp_result)
                return
            
            bt(idx + 1, tmp_result)
            bt(idx + 1, tmp_result + [nums[idx]])
        
        bt(0, [])
        return answer
