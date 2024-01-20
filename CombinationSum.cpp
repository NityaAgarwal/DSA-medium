//https://leetcode.com/problems/combination-sum/description/

class Solution {
public:
    void func(vector<vector<int>>&ans, vector<int>&candidates, int target, vector<int> currComb, int currSum, int index) {
        if (currSum > target) return ; //because any furthur addition will lead to sum increasing only
        if (currSum == target) {
            ans.push_back (currComb);
            return ; //because again, any furthur addition will lead to increase in sum
        }
        for (int i = index; i<candidates.size(); i++) {
            //case 1 - include current element
            currComb.push_back(candidates[i]);
            currSum += candidates[i];
            func(ans, candidates, target, currComb, currSum, i);
            //case 2 - not including the current element
            currComb.pop_back();
            currSum -= candidates[i];
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int>currComb;
        func(ans, candidates, target, currComb, 0, 0);
        return ans;
    }
};
