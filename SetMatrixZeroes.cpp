//https://leetcode.com/problems/set-matrix-zeroes/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        bool rowZero = false;

        //determining which rows and columns to be made 0
        for (int i = 0; i<m; i++) {
            for (int j = 0; j<n; j++) {
                if (matrix[i][j] == 0) {
                    //indicate in top row that this col needs to be marked 0
                    matrix[0][j] = 0;
                    //indicate in first col that this row needs to be marked 0
                    if (i > 0) matrix[i][0] = 0;
                    else rowZero = true;

                }
            }
        }

        //now make 0 as per markings, except first row and first col
        for (int i = 1; i<m; i++) {
            for (int j = 1; j<n; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        //first col 
        if (matrix[0][0] == 0) {
            for (int i = 0; i<m; i++) {
                matrix[i][0] = 0;
            }
        }
        
        //first row
        if (rowZero) {
            for (int i = 0; i<n; i++) {
                matrix[0][i] = 0;
            }
        }

    }
};
