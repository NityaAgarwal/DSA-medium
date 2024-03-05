//https://neetcode.io/problems/valid-tree

//video link for solution understanding - https://www.youtube.com/watch?v=fyDYM9rcr1Y

class Solution {
private: 
    bool dfs(int curr, int parent, vector<bool>&visited, vector<vector<int>>&adj) {
        if (visited[curr]) return false;
        visited[curr] = true;
        for (auto neighbours : adj[curr]) {
            if (neighbours != parent && !dfs(neighbours, curr, visited, adj)) {
                return false;
            }
        }
        return true;
    }
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        //need an adjacency list
        vector<vector<int>>adj(n); 
        for (auto e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        //need a vector of booleans initialised to false for marking the visited ones
        vector<bool>visited(n, false);

        //then we need to make call to the recursive function starting from node '0' 
        //we will take its parent as -1
        if (!dfs(0, -1, visited, adj)) {
            return false;
        }

        //lastly checked if all have been visited or not (this helps to check there is no unconnected node)
        for (auto v : visited) {
            if (!v) return false;
        }

        return true;
    }
};
