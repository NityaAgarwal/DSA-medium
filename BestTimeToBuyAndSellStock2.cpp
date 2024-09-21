// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int buy_price = prices[0]; 
        int sell_price = prices[0]; 
        int max_profit = 0;
        for (int i = 1; i<prices.size();i++) {
            if (prices[i] > sell_price) {
                //we are going to be greedy and check for more
                sell_price = prices[i];
            }
            else {
                if (sell_price > buy_price) max_profit += (sell_price - buy_price);
                buy_price = prices[i];
                sell_price = prices[i];
            }
        }
        max_profit += sell_price - buy_price;
        return max_profit;
    }
};
