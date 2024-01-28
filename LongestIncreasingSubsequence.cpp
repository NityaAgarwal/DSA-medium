//https://leetcode.com/problems/longest-increasing-subsequence/description/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>dp(nums.size(), 1);
        dp[0] = 1; //default case
        for (int i = 1; i<nums.size(); i++) {
            for (int j = i-1; j>=0; j--) {
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i], 1+dp[j]);
                }
            }
        }
        sort(dp.begin(), dp.end());
        return dp[nums.size()-1];
    }
};
