"""
Runtime: 100 ms, faster than 80.74% of Python3 online submissions for Maximum Product Subarray.
Memory Usage: 14.3 MB, less than 98.87% of Python3 online submissions for Maximum Product Subarray.
"""
class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        """
        nums 를 하나씩 순회하면서 이전에 나왔던 숫자들 + 해당 num 까지 고려했을떄의 최대 값을 저장해두고 업데이트해 나간다. 
        
        단, nums 에 음수가 끼어 있어서 단순히 최댓값만을 기록하면 정답을 구할수가 없다. 
        따라서 순회 중 해당 위치의 숫자까지 고려했을 때 최대값, 최소값 같이 저장해놓고 업데이트하면서 진행한다.
        """
        
        cur_max = nums[0]
        cur_min = nums[0]
        max_prod = nums[0]
        
        for num in nums[1:]:
            cur_max_prev = cur_max
            cur_max = max(num, cur_max_prev * num, cur_min * num)
            cur_min = min(num, cur_max_prev * num, cur_min * num)
            max_prod = max(max_prod, cur_max, cur_min)
        
        return max_prod
