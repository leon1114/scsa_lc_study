"""
Runtime: 715 ms, faster than 88.95% of Python3 online submissions for Gas Station.
Memory Usage: 19 MB, less than 78.64% of Python3 online submissions for Gas Station.
"""

class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        """
        sum(cost) > sum(gas) 면 완주 불가능. 
        sum(gas) >= sum(cost) 라면, 어디서 시작해야 circuit 완주 가능한지 알 수 있어야 한다. 
        
        index i 부터 시작, array 끝까지 spare 를 더해나갔을 때, spare 의 합이 0 보다 큰 마지막 index i 를 찾으면 됨. 
        위와 같이 i 를 찾으면, 
        
        전체 spare 는 0 보다 크다는 것이 보장된 상태에서, 
        - 0 ~ i - 1 까지의 spare 합은 0 보다 작음 
        - i ~ 마지막 index 까지의  spare 합은 0 ~ i - 1 의 spare 적자를 충분히 매꿀 수 있는 수준이 됨. 
        - 만약 위 조건을 만족하는 i 보다 앞에서 시작하게 된다면, 진행하는 도중 무조건 gas 부족으로 멈춰서게됨. 
        
        """
        if sum(cost) > sum(gas):
            return -1
        
        start_idx = 0
        total_spare = 0
        
        for i in range(len(gas)):
            spare_gas = gas[i] - cost[i]
            total_spare += spare_gas
            if total_spare < 0:
                start_idx = i + 1
                total_spare = 0
        
        return start_idx
            
            
        
