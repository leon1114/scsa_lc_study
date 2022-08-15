"""
Runtime: 715 ms, faster than 88.95% of Python3 online submissions for Gas Station.
Memory Usage: 19.4 MB, less than 25.37% of Python3 online submissions for Gas Station.
"""

class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        """
        index 0 부터 시작해서 spare gas (gas - cost) 를 계속해서 더해 나간다. 
        
        마지막 station 까지 도착했을 때, spare gas 의 합이 0보다 작으면 circuit 완주가 불가능.
        만약 spare gas 합이 0 보다 크다면, 어디서 시작해야 circuit 완주 가능한지 알 수 있어야 한다. 
        
        spare gas 의 합 (total gas) 가 0 보다 크다면, 어디서 시작해야 완주가능할까? 
        
        index 0 ~ i 까지의 total gas 가 가장 작아지는 index i 를 찾고, 그 바로 다음 index 에서 시작하면 됨.
        첫 번째 예시 문제 기준, 
        - index 0 ~ 2 까지의 spare gas 합은 -6 이 됨. 
        - total gas 의 합은 0 임. 
        - 즉, index 3 부터 마지막까지 spare gas 를 더하면 6 이됨 -> 0 ~ 2 까지의 소모량을 모두 충족할 수 있는 spare gas 를 모을 수 있음. 
        
        
        """
        
        min_cumulated_spare = float('inf')
        min_cumulated_spare_idx = -1
        
        total_gas = 0
        
        for i, (_gas, _cost) in enumerate(zip(gas, cost)):
            total_gas += (_gas - _cost)
            
            if total_gas < min_cumulated_spare:
                min_cumulated_spare_idx = i
                min_cumulated_spare = total_gas
        
        return -1 if total_gas < 0 else (min_cumulated_spare_idx + 1) % len(gas)
        
