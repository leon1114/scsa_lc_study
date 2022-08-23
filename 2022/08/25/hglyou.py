"""
Runtime: 107 ms, faster than 74.87% of Python3 online submissions for Maximum Product Subarray.
Memory Usage: 14.4 MB, less than 37.44% of Python3 online submissions for Maximum Product Subarray.
"""
class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        """
        nums 를 하나씩 순회하면서 이전에 나왔던 숫자들 + 해당 num 까지 고려했을떄의 최대 값을 저장해두고 업데이트해 나간다. 
        
        단, nums 에 음수가 끼어 있어서 단순히 최댓값만을 기록하면 정답을 구할수가 없다. 
        따라서 순회 중 해당 위치의 숫자까지 고려했을 때 최대값, 최소값 같이 저장해놓고 업데이트하면서 진행한다.
        """
        
        max_pos = nums[0]
        min_neg = nums[0]
        max_prod = nums[0]
        
        for num in nums[1:]:
            max_pos_prev = max_pos
            max_pos = max(num, max_pos_prev * num, min_neg * num)
            min_neg = min(num, max_pos_prev * num, min_neg * num)
            max_prod = max(max_prod, max_pos, min_neg)
        
        return max_prod
