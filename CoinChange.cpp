//https://leetcode.com/problems/coin-change/

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int>dp(amount+1, amount+1);
        //initialised the least number of coins corresponding to every amount as max
        //amount+1 can be considered as maximum (iske barabar tak nahi jaa sakta) 
        dp[0] = 0; //setting as default
        for (int i = 1; i<=amount; i++) {
            for (auto c: coins) {
                if (c <= i)
                dp[i] = min (dp[i], 1+dp[i-c]);
            }
        }
        return (dp[amount] == amount +1) ? -1 : dp[amount];
    }
};
