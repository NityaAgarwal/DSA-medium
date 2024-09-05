//https://leetcode.com/problems/coin-change-ii/description/

//will try tabulation and space optimisation later, abhi aise karliya hai

class Solution {
public:
    int func(int index, int amount, vector<int>& coins, vector<vector<int>>&dp) {
        //base case - 
        if (index == 0) {
            if (amount % coins[0] == 0) return 1; //combination found
            else return 0; //no  combination found
        }
        if (dp[index][amount] != -1) return dp[index][amount]; //we had already calculated it
        if (amount == 0) return 1; //combination found

        //two cases - 
        //take the coin at current index
        int taken = 0;
        if (coins[index]<=amount) taken = func(index, amount-coins[index], coins, dp);
        //do not take the coin at current index
        int not_taken = func(index-1, amount, coins, dp);

        dp[index][amount] = taken + not_taken;
        return dp[index][amount];

    }
    int change(int amount, vector<int>& coins) {
        if (amount == 0) return 1; //this question is considering empty subset as an answer 
        int n = coins.size();
        vector<vector<int>>dp(n, vector<int>(amount+1, -1));
        return func(n-1, amount, coins, dp);
    }
};
