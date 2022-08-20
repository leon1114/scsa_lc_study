/*
Runtime: 10 ms, faster than 40.25% of C online submissions for Best Time to Buy and Sell Stock II.
Memory Usage: 7 MB, less than 16.58% of C online submissions for Best Time to Buy and Sell Stock II.

이게 맞나?
이게 미디움 난이도 맞음???
뭔가 조건이 더 있나?
*/


int maxProfit(int* prices, int pricesSize){

    int profit = 0;
    for (int i = 1; i < pricesSize; i++)
    {
        if(prices[i-1] < prices[i]){
            profit+=prices[i] - prices[i-1];
        }
    }    
    return profit;
}
