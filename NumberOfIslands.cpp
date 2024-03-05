//https://leetcode.com/problems/number-of-islands/description/

class Solution {
private: 
    void func(vector<vector<char>>& grid, vector<vector<int>>& marked, int row, int col) {
        //check out of bounds
        if (row < 0 || col < 0 || row == grid.size() || col == grid[0].size() || //out of bounds
        grid[row][col] - '0' == 0 || //if the grid element is 0
        marked[row][col] == 1) return ; //already included in an island
        
        
                //visiting this '1' for the first time
                marked[row][col] = 1;
                //after marking, now recursively call for adjacent cells
                func(grid, marked, row-1, col);
                func(grid, marked, row+1, col);
                func(grid, marked, row, col-1);
                func(grid, marked, row, col+1);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>marked(m, vector<int>(n, 0));
        for (int i = 0; i<m; i++) {
            for (int j = 0; j<n; j++) {
                if (marked[i][j] == 0 && grid[i][j] == '1') {
                    func(grid, marked, i, j);
                    count++;
                }
            }
        }
        return count;
    }
};
