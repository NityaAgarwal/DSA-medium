//https://leetcode.com/problems/house-robber/description/

//approach 1 - brute force approach (imagine it using a state space tree - might give TLE for larger size of nums input
class Solution {
public: 
    int func (vector<int>&nums, int total, int index) {
        if (index >= nums.size()) return total; //because of out of bounds, so any furthut addition cant be done - hence we are returning the total as it is
        int sum1 = func(nums, total+nums[index], index+2); //either i rob the current house - then i wont be able to check for the immediate next house, so instead of index+1, iam taking index+2
        int sum2 = func(nums, total, index+1); //or i dont rob the current house, and will check from i+th house now
        return max(sum1, sum2);
    }
int rob(vector<int>& nums) {
return func(nums, 0, 0);
}};
//approach 2 - using the concept of DP - 
class Solution {
public:
    int rob(vector<int>& nums) {
        for (int i = 0; i<nums.size(); i++) {
            if (i == 0) continue; //just written for understanding purposes
            if (i == 1) nums[i] = max(nums[i-1], nums[i]);
            else {
                /*
                     case 1 - you rob ith house
                    -means ek toh ith house ka money count karoge
                    -secondly, since you robbed ith house, you cant include i-1th result
                    -thirdly, ab i-2th result be add karlo

                     case 2 - you dont rob ith house
                     - so take the value saved corresponding to i-1th house
                */
                nums[i] = max(nums[i]+nums[i-2], nums[i-1]);
            }
        }
        return nums[nums.size()-1];
    }
};
