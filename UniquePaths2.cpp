//quite same as the previous one, just a minor addition

//note - the code below is using memoization technique, you can improve it further by tabulation and then space optimisation

class Solution {
public:
    int func(int row, int col, vector<vector<int>>& obstacleGrid, vector<vector<int>>&dp, int&m, int&n) {
        if (row >= m || col >= n) return 0; //no valid way exists
        if (dp[row][col] != -1) return dp[row][col]; //because already calculated
        if (obstacleGrid[row][col] == 1) {
            dp[row][col] = 0;
            return 0;
        }
        if (row == m-1 && col == n-1) return 1; //valid way found
        int ways = 0;
        ways += func(row+1, col, obstacleGrid, dp, m, n); //move down
        ways += func(row, col+1, obstacleGrid, dp, m, n); //move right
        dp[row][col] = ways;
        return ways;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid[0][0] == 1) return 0;
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if (obstacleGrid[m-1][n-1] == 1) return 0;
        vector<vector<int>>dp(m, vector<int>(n, -1));
        return func(0, 0, obstacleGrid, dp, m, n);
    }
};
