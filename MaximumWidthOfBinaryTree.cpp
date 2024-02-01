//https://leetcode.com/problems/maximum-width-of-binary-tree/

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        /*
        1. width at any level is the distance bw the two extreme nodes existing at that level
        2. so width of the entire BT comes out to be the maximum of these individual widths
        3. since we are talking about 'levels' - we will use level order traversal
        */
        if (!root) return NULL;
        queue<pair<TreeNode*, int>>q;
        q.push({root, 0}); //assuming 0 based indexing of the BT
        long long curr_id; //taken as long long to avoid future potential overflow
        int ans = 0;
        while (!q.empty()) {
            /*at every level - i need to know the following
            1. size of the queue (queue size at a moment will be equal to the 
               number of nodes at that level, so we will take advantage of that)
            2. need  to declare a first_id and last_id of that level
            3. need minimum id - minimum id at a level is the first_id of that level*/
            int size = q.size();
            int first_id, last_id;
            int min_id = q.front().second;
            //will subtract min-id from every node of curr level so that every level's
            //indexing looks like 0,1,2,3----
            //Again, it is another way to avoid overflow
            for (int i = 0; i<size; i++) {
                TreeNode* node = q.front().first;
                curr_id = q.front().second - min_id; 
                q.pop();
                if (i == 0) first_id = curr_id;
                if (i == size-1) last_id = curr_id;
                if (node->left) q.push({node->left, 2*curr_id +1});
                if (node->right) q.push({node->right, 2*curr_id +2});
            }
            ans = max(ans, last_id - first_id + 1);
        }
        return ans;
    }
};
