// https://leetcode.com/problems/validate-binary-search-tree/description/

class Solution {
private: 
    bool isValidBSTUtil(TreeNode* root, long minValue, long maxValue) {
        if (!root) return true;
        
        if (root->val <= minValue || root->val >= maxValue) return false;
        
        // Check left subtree with updated maxValue and right subtree with updated minValue
        return isValidBSTUtil(root->left, minValue, root->val) && 
               isValidBSTUtil(root->right, root->val, maxValue);
    }
    
public:
    bool isValidBST(TreeNode* root) {
        return isValidBSTUtil(root, LONG_MIN, LONG_MAX);
    }
};
