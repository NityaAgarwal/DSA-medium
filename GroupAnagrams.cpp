//https://leetcode.com/problems/group-anagrams/description/

//solved myself in O(n) time and space complexity :`)

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;
        for (auto x: strs) {
            string curr_sorted = x; 
            sort(curr_sorted.begin(), curr_sorted.end());

            //if the anagram template is already there in the map or not
            if (!m.count(curr_sorted)) {
                m[curr_sorted] = {x}; 
            }
            else m[curr_sorted].push_back(x);
        }

        vector<vector<string>>ans;
        while (!m.empty()) {
            auto it = m.begin();
            ans.push_back(it->second);
            m.erase(it);
        }

        return ans;
    }
};
