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
    TreeNode *first= nullptr, *second=nullptr, *prev = nullptr;
    /*
    if you want to change the global variables to local variable, then you can change as follows:
    void helper(TreeNode* root, TreeNode*& prev, TreeNode*& first, TreeNode*& second)
    */
    void recoverTree(TreeNode* root) {
        helper(root);
        if(first != nullptr && second != nullptr)
            swap(first->val, second->val);
        
    }
    void helper(TreeNode* root){
        if(root == nullptr) return;
        helper(root->left);
        if(prev != nullptr && root->val < prev->val){
            if(first == nullptr){
                first = prev;
            }
            second = root;
           
        }
        prev = root;
        helper(root->right);
    }
    
    
};
