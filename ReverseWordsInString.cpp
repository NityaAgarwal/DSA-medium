//https://leetcode.com/problems/reverse-words-in-a-string/description/

class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        int i = 0;
        int j = 0;

        string p = "";
        string ans = "";

        
        for (; i<n; i++) {
            if (s[i] != ' ') {
                p += s[i];
            }

            else if (s[i] == ' ' && p != "") {
                ans = p + " " + ans;
                p = ""; //reset p for next iteration
            }

            else continue;
        }
        if (p != "") {
            ans = p + " " + ans;
        }

        return ans.substr(0, ans.size()-1); 
        //this we are doing because after the first iteration, there will be 
        //an extra blank space after the last word of the final answer, which needs to
        //be removed
    }
};
