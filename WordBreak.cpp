https://leetcode.com/problems/word-break/description/

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<bool> dp (n+1, false);
        //default - dp[last iterator of the string (size+1)] set as True
        dp[n] = true;
        //loop will run for all indices of the string, but backwards
        for (int i = n-1; i>=0; i--) {
            //at every stage we shall check all the words in wordDict
            for (auto w : wordDict) {
                if (i+w.size() <= n && w == s.substr(i, w.size())) {
                    dp[i] = dp[i+w.size()];
                    if (dp[i] == true) break;
                }
            }
        }
        return dp[0];
    }
};
