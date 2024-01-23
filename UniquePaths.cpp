//https://leetcode.com/problems/unique-paths/description/

class Solution {
public:
    int func(int m, int n, int row, int column, vector<vector<int>>&dp){
        if (row == m-1 && column == n-1) return 1;
        if (row > m-1 || column > n-1) return 0;
        if (dp[row][column] != -1) return dp[row][column];

        int paths = 0;
        //either robot takes a step to the right
        paths = func(m, n, row, column+1, dp);
        //or, robot takes a step below
        paths += func(m, n, row+1, column, dp);

        dp[row][column] = paths;
        return paths;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return func(m, n, 0, 0, dp);
    }
};
