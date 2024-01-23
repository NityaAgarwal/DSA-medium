//https://leetcode.com/problems/jump-game/description/

//M1 - one pass answer, performs much better than the next method
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int last_pos = n-1; 
        for (int i = n-2; i>=0; i--) {
            if (i + nums[i] >= last_pos) {
                last_pos = i;
            }
        }
        return last_pos == 0;
    }
};
//M2 - i came up with this dp approach - it is however it is peforming not so well time wise
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return true; //because the only index is the last index

        vector<bool>dp(n, false);
        //we will set the last value as default - true
        dp[n-1] = true;
        for (int i = n-2; i>=0; i--) {
            int possibilities = nums[i];
            for (int j = 1; j<=possibilities && i+j<n; j++) {
                if (dp[i+j]) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[0];
    }
};
