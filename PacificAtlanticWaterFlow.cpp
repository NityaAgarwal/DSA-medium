//https://leetcode.com/problems/pacific-atlantic-water-flow/description/

class Solution {
private: 
    void dfs(int row, int col, vector<vector<int>>&visit, int prevHeight, vector<vector<int>>&heights) {
        int total_r = heights.size();
        int total_c = heights[0].size();
        // vector<vector<int>>v;
        //base conditions -
        if (row < 0 || col < 0 || row == total_r || col == total_c || //out of bounds
        visit[row][col] || //means already added in the visited list, so why bother again
        heights[row][col] < prevHeight) { //wont flow in this condition
            return ;
        }
        //update the current cell's status
        visit[row][col] = 1; 
        //recursive call its neighbours too
        dfs(row-1, col, visit, heights[row][col], heights);
        dfs(row+1, col, visit, heights[row][col], heights);
        dfs(row, col-1, visit, heights[row][col], heights);
        dfs(row, col+1, visit, heights[row][col], heights);
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int total_rows = heights.size();
        int total_cols = heights[0].size();
        vector<vector<int>>pac (total_rows, vector<int>(total_cols));
        vector<vector<int>>atl (total_rows, vector<int>(total_cols));

        for (int i = 0; i<total_rows; i++) {
            //leftmost column
            dfs(i, 0, pac, heights[i][0], heights);
            //rightmost column
            dfs(i, total_cols-1, atl, heights[i][total_cols-1], heights);
        }

        for (int i = 0; i<total_cols; i++) {
            //leftmost column
            dfs(0, i, pac, heights[0][i], heights);
            //rightmost column
            dfs(total_rows-1, i, atl, heights[total_rows-1][i], heights);
        }

        vector<vector<int>> ans;
        for (int i = 0; i<total_rows; i++) {
            for (int j = 0; j<total_cols; j++) {
                if (pac[i][j] && atl[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }

        return ans;
    }
};
