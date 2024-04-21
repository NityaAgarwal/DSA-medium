//https://leetcode.com/problems/longest-consecutive-sequence/description/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        /*
        First turn the input into a set of numbers. That takes O(n) and then we can ask in O(1) whether we have a certain number.

        Then go through the numbers. If the number x is the start of a streak (i.e., x-1 is not in the set), 
        then test y = x+1, x+2, x+3, ... and stop at the first number y not in the set. 
        The length of the streak is then simply y-x and we update our global best with that. 
        Since we check each streak only once, this is overall O(n). This ran in 44 ms on the OJ, 
        one of the fastest Python submissions.
        */
        unordered_set <int> m;
        for (auto x : nums) {
            if (!m.count(x)) m.insert(x);
        } 

        int best = 0;
        for (auto x : nums) {
            //start of the streak
            if (!m.count(x-1)) {
                int y = x;
                while (m.count(y+1)) {
                    y++;
                }
                best = max (best, y-x+1);
            }
        }

        return best;
    }
};
