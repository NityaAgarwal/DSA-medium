//https://leetcode.com/problems/maximum-product-subarray/description/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        //step1 - maximum might be one single element of the vector
        int maxi = INT_MIN;
        for (auto n: nums) {
            maxi = max(n, maxi);
        }

        //step2 - will maintain currMax and currMin - dp approach - because they will be 
        //carried forward and result of newer iterations will depend on older ones
        int currMin = 1;
        int currMax = 1;
        for (int i = 0; i<nums.size(); i++) {
            //if any element is 0, then currMax/Min values need to be reset as 1
            //because if not reset, they will make all results thereon to be equal to 0
            if (nums[i]==0) {
                currMin = 1; currMax = 1;
                continue; //obv, we have nothing do with furthur calculations for this element
            }

            int temp = currMax*nums[i];
            currMax = max(nums[i], max(currMax*nums[i], currMin*nums[i]));
            currMin = min(nums[i], min(temp, currMin*nums[i]));
            maxi = max(maxi, currMax);
        }
        return maxi;
    }
};
