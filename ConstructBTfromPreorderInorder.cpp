//https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0) return NULL;
        /*
        inorder traversal -  left tree, root, right tree
        preorder traversal - root, left tree, right tree

        preorder will tell the value of the current node
        then we will find its position in inorder - say index j
        inorder to the left of j will go in the 
        */

        //take the first element of preorder as current node to be constructed
        int val = preorder[0];
        TreeNode* curr = new TreeNode (val);
        //find its index in inorder
        auto itr = find(inorder.begin(), inorder.end(), val);
        int pos = itr - inorder.begin();
        //as many elements in left subtree of curr as is the number pos
        /* 
            Create a subvector using iterators
            vector<int> subVector(originalVector.begin() + i, originalVector.begin() + j);
        */
        vector<int> pre_left (preorder.begin()+1, preorder.begin()+pos+1);
        vector<int> pre_right (preorder.begin()+pos+1, preorder.end());
        vector<int> in_left (inorder.begin(), inorder.begin()+pos);
        vector<int> in_right (inorder.begin() + pos + 1, inorder.end());
        //call the recursive function - 
        curr->left = buildTree(pre_left, in_left);
        curr->right = buildTree(pre_right, in_right);
        //return the final ans - 
        return curr; 
    }
};
