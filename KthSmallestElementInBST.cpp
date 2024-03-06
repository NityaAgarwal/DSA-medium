//https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/

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
/* 
approach used- 
1. make inorder of the bst, store in a vector
2. access the required element*/
private: 
    void func(TreeNode* root, vector<int>&inorder) {
        //inorder is Left Root Right
        if (root->left) func(root->left, inorder);
        if (root) inorder.push_back(root->val);
        if (root->right) func(root->right, inorder);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int>inorder;
        //make the inorder vector
        func(root, inorder);
        //access the kth element (since it is given to be 1-based indexing, access the k-1st element)
        return inorder[k-1];
    }
};
