//https://leetcode.com/problems/binary-tree-level-order-traversal/description/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {}; //empty

        vector<vector<int>>ans;
        queue<pair<TreeNode*, int>>q;
        q.push({root, 1});
        TreeNode* node;
        int level;

        while (!q.empty()) {
            node = q.front().first;
            level = q.front().second;
            //push this node in the vector
            if (ans.size() == level) { //means already some enteries have been made from that level, so push the current node in that already existing entry
                ans[level-1].push_back(node->val);
            }
            else { //means that no entry corresponding to this level exists in the 'ans' vector, so we have to make a new one 
                vector<int>newLevel;
                newLevel.push_back(node->val);
                ans.push_back(newLevel);
            }
            //add its child nodes in the queue
            if (node->left) q.push({node->left, level+1});
            if (node->right) q.push({node->right, level+1});
            //pop the front
            q.pop();
        }
        return ans;
    }
};
