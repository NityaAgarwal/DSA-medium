//https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/description/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
/*
approach - 
find the given nodes, store each nodes path individually inside two diff stacks
first pop the uneven size of the bigger stack, make the two of equal size if not already
then one by one keep popping the two top elements till top of both is same
*/
private:
    void func(TreeNode* root, TreeNode* target, stack<TreeNode*>&s) {
        s.push(root);
        if (root == target) return;
        
        //for smaller value go to the left
        //for larger value go to the right 
        if (target->val < root->val) {
            func(root->left, target, s);
        }
        else func(root->right, target, s);
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        stack<TreeNode*>ps; //stack for node p
        stack<TreeNode*>qs; //stack for node q
        
        //prepare stacks for both
        func(root, p, ps);
        func(root, q, qs);

        //make the size of the stacks equal if unequal
        int psize = ps.size(); 
        int qsize = qs.size();
        if (psize > qsize) {
            for (int i = 0; i<psize - qsize; i++) {
                ps.pop();
            }
        }
        else if (psize < qsize) {
            for (int i = 0; i<qsize - psize; i++) {
                qs.pop();
            }
        }

        //now check the top elements and keep popping till same node attained
        while (!ps.empty()) {
            if (ps.top() == qs.top()) return ps.top();
            //else
            ps.pop(); qs.pop();
        }
        
        return root;
    }
};
