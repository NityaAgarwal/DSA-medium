//https://neetcode.io/problems/meeting-schedule-ii

/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<int>s;
        vector<int>e;
        for (int i = 0; i<intervals.size(); i++) {
            s.push_back(intervals[i].start);
            e.push_back(intervals[i].end);
        }
        sort(s.begin(), s.end());
        sort(e.begin(), e.end());
        int i = 0; int j = 0; //pointers for the start and end arrays
        int count = 0; //no of meetings running currently
        int maxi = 0; //max no of meetings that can run simultaneously
        while (i < s.size()) {
            if (s[i]<e[j]) {
                //new meeting started
                count ++;
                i ++;
            }
            else {
                //first the old meeting will end, then the new will start
                j ++;
                count --;
            }
                maxi = max (maxi, count);
        }
        return maxi;
    }
};
