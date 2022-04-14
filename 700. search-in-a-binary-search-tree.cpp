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
    TreeNode* searchBST(TreeNode* root, int val) {
        
        // iterative search.
        while(root != nullptr && root-> val != val){
            if(root->val > val) root = root->left;
            else root = root->right;
        }
        return root;
        
        /*
        // recursive
        
        if(root == nullptr || root->val == val) return root;
        else if(root-> val > val) return searchBST(root->left, val);
        return searchBST(root->right, val);
        
        
        */
    }
};
