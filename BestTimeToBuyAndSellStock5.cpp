// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/

class Solution {
public:
    int func(vector<int>& prices, int index, int buy, vector<vector<int>>&dp) {
        if (index >= prices.size()) return 0;

        if (dp[index][buy] != -1) return dp[index][buy];

        //either you can buy
        if (buy == 1) {
            //either you are buying today only
            int bought = 0;
            bought = -prices[index] + func(prices, index+1, 0, dp);
            //or you are not buying today
            int not_bought = func(prices, index+1, 1, dp);

            return dp[index][buy] = max(bought, not_bought);
        }
        //or you cannot buy
        else {
            //either you sell today only
            int sold = 0;
            sold = prices[index] + func(prices, index+2, 1, dp); //reason for this - this one is with COOLDOWN - 
          //that is, if sold today, then i cannot buy tomorrow. That is why instead of incrementing by 1, we incremented by 2, so that tomorrow gets skipped
            //or you dont sell today
            int not_sold = func(prices, index+1, 0, dp);

            return dp[index][buy] = max(sold, not_sold);
        }

        return 0; //this is just for writing purposes
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n, vector<int>(2, -1));
        return func(prices, 0, 1, dp);
    }
};
