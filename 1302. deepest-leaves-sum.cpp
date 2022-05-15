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
    int deepestLeavesSum(TreeNode* root) {
        int dep = depth(root);
        return sumofDepth(root, dep);
    }
    //get depth of tree
    int depth(TreeNode *root){
        
        if(!root) return 0;
        return 1+ max(depth(root->left), depth(root->right));
    }
    // cal sum of each node have in the depth
    int sumofDepth(TreeNode *root, int depth){
        
        if(!root) return 0;
        if(depth ==1) return root->val;
        return sumofDepth(root->left, depth-1) + sumofDepth(root->right,depth-1);
    }
};
