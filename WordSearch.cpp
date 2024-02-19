//https://leetcode.com/problems/word-search/description/

class Solution {
private: 
    bool dfs(vector<vector<char>>& board, string word, int index, vector<vector<bool>>&visited, 
    int row, int col) {
        if (index == word.size()) return true;
        if (row < 0 || col < 0 || row == board.size() || col == board[0].size()) return false;
        if (board[row][col] != word[index]) return false;
        if (visited[row][col]) return false; 

        visited[row][col] = true;
        //explore furthur
        bool found = dfs(board, word, index+1, visited, row+1, col) ||
        dfs(board, word, index+1, visited, row-1, col) ||
        dfs(board, word, index+1, visited, row, col+1) ||
        dfs(board, word, index+1, visited, row, col-1);
        //reset visited status
        visited[row][col] = false;
        return found;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>>visited(m, vector<bool>(n, false));
        for (int i = 0; i<m; i++) {
            for (int j = 0; j<n; j++) {
                if (dfs(board, word, 0, visited, i, j)) {
                    return true; 
                }
            }
        }
        return false;
    }
};
