//https://leetcode.com/problems/partition-equal-subset-sum/

//below solves via memoization, right now, further optimisations havent been taken into consideration

class Solution {
public:
    //note - 
    //ask for clarification from the interviewer if an empty subset is also considered or not
    //solution below is assuming it to be valid

    bool func(vector<int>&nums, int index, int target, vector<vector<int>>&dp) {
        //base case 
        if (target == 0) return true;
        if (index == 0) return nums[index] == target ? true: false;
        if (dp[index][target] != -1) return dp[index][target];

        //current is chosen
        bool chosen = false;
        if (nums[index] <= target) chosen = func(nums, index-1, target-nums[index], dp);
        //current is not chosen
        bool not_chosen = func(nums, index-1, target, dp);

        dp[index][target] = (chosen || not_chosen) ? 1 : 0;
        return dp[index][target];
    }
    bool canPartition(vector<int>& nums) {
        int total_sum = 0;
        for (auto x: nums) {
            total_sum += x;
        }
        if (total_sum % 2 != 0) return false; //because it cant be divided into two integers
        int n = nums.size();
        //memoize it 
        int target = total_sum/2;
        vector<vector<int>>dp(n, vector<int>(target+1, -1));
        //if i am able to find a subset with total/2 value, 
        //then the unchosen elements must be forming a subset with total/2 value too
        //such that together they will make sum = total
        return func(nums, n-1, target, dp);
    }
};
