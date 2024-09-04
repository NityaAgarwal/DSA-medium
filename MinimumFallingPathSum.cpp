//this is via the tabulation method - after this, the space optimisation problem will seem very simple

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>>dp(n, vector<int>(n, 0));
        //initialise the last row of the dp as the same as the matrix

        for (int i = 0; i<n; i++) {
            dp[n-1][i] = matrix[n-1][i];
        }

        //start from the second last row
        //uptil the first row
        for (int i = n-2; i>=0; i--) {
            for (int j = 0; j<n; j++) {
                int left = INT_MAX; //if this doesnt exist, then it should be an impossible path
                int right = INT_MAX; //if this doesnt....
                if (j > 0) left = dp[i+1][j-1];
                if (j < n-1) right = dp[i+1][j+1];
                int down = dp[i+1][j];

                dp[i][j] = matrix[i][j] + min(left, min(down, right));
            }
        }

        //take the minimum from the first row
        int mini = INT_MAX;
        for (int i = 0; i<n; i++) {
            if (dp[0][i] < mini) mini = dp[0][i];
        }

        return mini;
    }
};
