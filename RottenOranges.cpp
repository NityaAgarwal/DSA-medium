//https://leetcode.com/problems/rotting-oranges/

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q; // to store the index of all rotten oranges at a certain time
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) q.push(make_pair(i, j));
            }
        }

        int min = 0;
        while (!q.empty()) {
            int size = q.size();
            bool flag = false; // to mark if any fresh orange made rotten in this round
            for (int i = 0; i < size; i++) {
                // take indices of the first rotten orange in the queue
                int row = q.front().first;
                int col = q.front().second;
                q.pop();

                // check orange above
                if (row-1 >= 0 && grid[row - 1][col] == 1) {
                    grid[row - 1][col] = 2; // make this rotten
                    q.push(make_pair(
                        row - 1, col)); // add to the queue of rotten oranges
                    flag = true;
                }
                // check orange below
                if (col-1 >= 0 && grid[row][col - 1] == 1) {
                    grid[row][col - 1] = 2; // make this rotten
                    q.push(make_pair(
                        row, col - 1)); // add to the queue of rotten oranges
                    flag = true;
                }
                // check orange to left
                if (row+1 < m && grid[row + 1][col] == 1) {
                    grid[row + 1][col] = 2; // make this rotten
                    q.push(make_pair(
                        row + 1, col)); // add to the queue of rotten oranges
                    flag = true;
                }
                // check orange to right
                if (col+1 < n && grid[row][col + 1] == 1) {
                    grid[row][col + 1] = 2; // make this rotten
                    q.push(make_pair(
                        row, col + 1)); // add to the queue of rotten oranges
                    flag = true;
                }
            }

            // now if flag = true
            // then atleast one of the neighbouring oranges of one of the
            // current rotten oranges was made rotten so a minute needs to be
            // added
            if (flag)
                min++;
        }

        // last step - check if any orange still remains fresh
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1)
                    return -1;
            }
        }

        return min;
    }
};
