//https://leetcode.com/problems/longest-substring-without-repeating-characters/description/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set <char> set;
        int maxi = 0; 
        int first = 0; 
        for (int last = 0; last < s.size(); last++) {
            while (set.find(s[last]) != set.end()) {
                set.erase(s[first]);
                first += 1;
            }
            set.insert(s[last]);
            maxi = max(maxi, last - first + 1);
        }
        return maxi;
    }
};
