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
    int sumRootToLeaf(TreeNode* root, int helper = 0) {
        if(!root) return 0;
        
        helper = (helper * 2 + root->val);
        
        return root->left == root->right ? helper : sumRootToLeaf(root->left, helper) + sumRootToLeaf(root->right, helper);
    }
/*
public:
    int sumRootToLeaf(TreeNode* root) {
        return dfs(root,0);
    }
    
    int dfs(TreeNode* root ,int val)
    {
        if(root == NULL)
            return 0;
        val = 2*val + root->val;
        if(root->left == NULL && root->right == NULL)
            return val;
        else
        {
            int left = dfs(root->left,val);
            int right = dfs(root->right,val);
            return left + right;
        }
        
    }
*/
};
