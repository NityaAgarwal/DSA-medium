//https://neetcode.io/problems/count-connected-components

class Solution {
private: 
    void dfs(int node, unordered_map<int, vector<int>> &m, unordered_map<int,int>&visited) {
        if (visited.count(node)) return;

        visited[node] = 1;
        if (m[node].size() != 0) {
            for (int i = 0; i<m[node].size(); i++) {
                dfs(m[node][i], m, visited);
            }
        }
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        //need a visited set
        unordered_map<int, int>visited;

        //need a counter
        int count {0};

        //make adjacency list for each node
        unordered_map<int, vector<int>> m;
        for (auto& edge : edges) {
            int node1 = edge[0], node2 = edge[1];
            m[node1].push_back(node2);
            m[node2].push_back(node1);
        }

        //now run a dfs on all nodes in the list
        for (int i = 0; i<n; i++) {
            if (!visited.count(i)) {
                dfs(i, m, visited);
                count++;
            }
        }

        return count;
    }
};
