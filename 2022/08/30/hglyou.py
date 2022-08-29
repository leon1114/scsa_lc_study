"""
Runtime: 66 ms, faster than 61.87% of Python3 online submissions for Find Peak Element.
Memory Usage: 14.1 MB, less than 44.04% of Python3 online submissions for Find Peak Element.
"""
class Solution:
    """
    local maximum 라도 상관없으니 찾기만하면 됨. 
    
    따라서 정렬되어있지 않은 array 지만 바이너리 서치로 찾을 수 있음. 
    """
    def findPeakElement(self, nums: List[int]) -> int:
        nums = [float('-inf')] + nums + [float('-inf')]
        l, r = 1, len(nums) - 2
        
        """
        항상 헷갈리는 바이너리 서치의 종료 조건과 cursor 이동에 대한 내용 
        - 가장 마지막 상황을 가정하고 조건들을 정해나가면 된다. 
        - 가장 마지막 상황 : inf, 1, 1, 이 남은 경우. l, r = 1, 2
            - m = 1
            - nums[1] >= nums[2] 임 
            - r 은 2 에서 1이 됨. 
            - 이 때 l <= r 을 종료조건으로 사용하면 무한루프 
            - l < r 로 루프 끝내고 l 을 정답으로 사용하면 됨. 
        """
        while l < r:
            m = (l + r) // 2
            if nums[m] >= nums[m+1]:
                r = m
            else:
                l = m + 1
        
        return l - 1
        
