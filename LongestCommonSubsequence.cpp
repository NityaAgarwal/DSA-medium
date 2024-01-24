//https://leetcode.com/problems/longest-common-subsequence/description/

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        vector<vector<int>>dp(m+1, vector<int>(n+1, 0));
        for (int i = m-1; i>=0; i--) {
            for (int j = n-1; j>=0; j--) {
                if (text1[i] == text2[j]) dp[i][j] = dp[i+1][j+1] + 1;
                else dp[i][j] = max(dp[i][j+1], dp[i+1][j]);
            }
        }
        //by doing this we have filled the dp table
        
        return dp[0][0];
    }
};
