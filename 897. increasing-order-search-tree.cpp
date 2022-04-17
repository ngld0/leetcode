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
private:
    
    TreeNode* ret = new TreeNode(0);
    TreeNode *ans;
    void inorder(TreeNode *root){
        if(root == nullptr) return;
        inorder(root->left);
        //TreeNode* node = new TreeNode(root->val);
        ret->right = new TreeNode(root->val);
        ret = ret->right;
        inorder(root->right);
    }
public:
    TreeNode* increasingBST(TreeNode* root) {
        ans = ret;
        inorder(root);
        return ans->right;
    }
};
