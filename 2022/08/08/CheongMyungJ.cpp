//Runtime: 14 ms, faster than 40.39% of C++ online submissions for Best Time to Buy and Sell Stock II.
//Memory Usage: 13.1 MB, less than 57.64% of C++ online submissions for Best Time to Buy and Sell Stock II.
//오늘 문제 개꿀~

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ret = 0;
        int before = prices[0];
        for (int i = 1; i < prices.size(); i++){
            if (before < prices[i])
                ret += prices[i] - before;
            before = prices[i];
        }
        return ret;
    }
};
