//https://leetcode.com/problems/spiral-matrix/description/

class Solution {
private: 
    void loop(vector<vector<int>> matrix, vector<int>& ans) {

        int m = matrix.size();
        int n = matrix[0].size();
        int count = m*n; 
        
        int f_row = 0;
        int l_row = m-1;
        int f_column = 0; 
        int l_column = n-1;

        int i = f_row;
        int j = f_column;

    while (1) {
        //step - 1 : top row
        for (int j = f_column; j<=l_column; j++) {
            ans.push_back(matrix[f_row][j]);
        }
        f_row ++;
        if (ans.size() == count) return;

        //step - 2 : last column
        for (int i = f_row; i<=l_row; i++) {
            ans.push_back(matrix[i][l_column]);
        }
        l_column --;
        if (ans.size() == count) return;

        //step - 3 : bottom row
        for (int j = l_column; j>=f_column; j--) {
            ans.push_back(matrix[l_row][j]);
        }
        l_row --;
        if (ans.size() == count) return;

        //step - 4 : first column
        for (int i = l_row; i>= f_row; i--) {
            if (ans.size() != count) ans.push_back(matrix[i][f_column]);
            else return;
        }
        f_column ++;
        if (ans.size() == count) return;
    }
        
    }
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>ans;
        loop(matrix, ans);
        return ans;
    }
};
