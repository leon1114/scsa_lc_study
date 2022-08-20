class Solution:
    """
    Runtime: 90 ms, faster than 62.57% of Python3 online submissions for Best Time to Buy and Sell Stock II.
    Memory Usage: 15.3 MB, less than 23.82% of Python3 online submissions for Best Time to Buy and Sell Stock II.
    """
    def maxProfit(self, prices: List[int]) -> int:
        """
        prices 에서 monotonically increasing sequence 들을 먼저 발라낸다. 
        그 다음 sequence 들의 시작, 끝값의 차이를 다 더하면 됨. 
        monotonically increasing sequence 들 끼리는 overlap 이 없으므로 단순히 더해주기만 하면 된다. 
        """
        
        total_profit = 0
        
        start_idx = -1
        for idx, price in enumerate(prices[:-1]):
            if price <= prices[idx + 1]:
                if start_idx == -1:
                    start_idx = idx
            else:
                if start_idx != -1:
                    total_profit += price - prices[start_idx]
                    start_idx = -1
        
        if start_idx != -1:
            total_profit += prices[-1] - prices[start_idx]
        
        return total_profit
