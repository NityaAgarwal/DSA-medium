//https://leetcode.com/problems/non-overlapping-intervals/description/

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int ans = 0; 
        int prev = 0; //the first interval of the vector
        for (int curr = 1; curr<intervals.size(); curr++) {
            //check if overlap
                //they overlap if curr start is less than prev end
                if (intervals[curr][0] < intervals[prev][1]) {
                    ans ++;
                    //now you shall remove any one of them - 
                    //it will be more beneficial to remove the one that ends last
                    //because it then has less chances of overlapping with next one
                    if (intervals[curr][1] > intervals[prev][1]) {
                        //means prev ended first
                        //so remove the curr
                        continue;
                        //continue because this means curr kabhi next itr mai aayega hi nahi
                        //picture mai. Jo next waala aaeyga voh issi prev se compare hoga
                    }
                }
                prev = curr; 
        }
        return ans; 
    }
};
