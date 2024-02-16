//https://leetcode.com/problems/rotate-image/description/

/*
step1 - take transpose
step2 - reverse each row
*/

class Solution {
private: 
    void transpose(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i<n; i++) { //check whether till n or n/2
            for (int j = i+1; j<n; j++) {
                if (i!=j) swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
    void reverseRows(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i<n; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
public:
    void rotate(vector<vector<int>>& matrix) {
        //step 1 - take transpose of the matrix
        //step 2 - reverse each row
        transpose(matrix);
        reverseRows(matrix);
    }
};
