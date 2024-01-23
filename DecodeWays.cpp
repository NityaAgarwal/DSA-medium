//https://leetcode.com/problems/decode-ways/

class Solution {
public:
    int func(string s, int index, vector<int>&dp) {
        if (index == s.size()) return 1;
        if (s[index] == '0') return 0;
        if (dp[index] != -1) {
            //means we must have visited it before, therefore its value got updated to
            //something that's no longer the initialised -1
            return dp[index];
        }
        int ways = 0;
        //call for self (single digit: 1-9. Note, single digit 0 already handled above)
        ways = func(s, index+1, dp);
        //case 2, call for 2 digit number
        if (index+1 < s.size() && 
        (s[index] == '1' || (s[index] == '2' && s[index+1] <= '6'))) {
            ways += func(s, index+2, dp);
        }

        dp[index] = ways;
        return ways;
    }
    int numDecodings(string s) {
        vector<int>dp(s.size(), -1);
        return func(s, 0, dp);
    }
};
