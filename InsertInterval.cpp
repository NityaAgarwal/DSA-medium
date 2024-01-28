//https://leetcode.com/problems/insert-interval/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int i = 1;
        vector<vector<int>>ans;
        while (i<intervals.size()) {
            //check if they overlap
            if (intervals[i][0] <= intervals[i-1][1]) {
                //this means they overlap
                //so they should be merged
                intervals[i][0] = intervals[i-1][0];
                intervals[i][1] = max(intervals[i-1][1], intervals[i][1]);
            }
            else ans.push_back(intervals[i-1]);
            i++;
        }
        // push the last interval or the merged interval
        ans.push_back(intervals.back());
        return ans;
    }
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        return merge(intervals);
    }
};
