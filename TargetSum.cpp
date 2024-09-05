//https://leetcode.com/problems/target-sum/

//note - be vary of indexing in this one
//also note - below solution is via memoization, try tabulation and space optimisation later

class Solution {
public:
    int func(vector<int>& nums, int index, int target, vector<vector<int>>& dp) {
        if (target > 1000 || target < -1000) return 0;
        if (index < 0) return target == 0 ? 1 : 0; // Only one valid way if target is 0 at the last index
        if (dp[index][target + 1000] != -1) return dp[index][target + 1000];

        // Two cases: add current element positively or negatively
        int pos = func(nums, index - 1, target - nums[index], dp); // Positive
        int neg = func(nums, index - 1, target + nums[index], dp); // Negative

        dp[index][target + 1000] = pos + neg;
        return dp[index][target + 1000];
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        // DP array size needs to be [n][2001] due to range [-1000, 1000]
        vector<vector<int>> dp(n, vector<int>(2001, -1));
        return func(nums, n - 1, target, dp);
    }
};
