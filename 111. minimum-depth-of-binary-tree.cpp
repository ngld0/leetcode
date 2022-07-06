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
    //find min
    int minDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        int d1 = minDepth(root->left);
        int d2 = minDepth(root->right);
        if(root->left == nullptr) 
            return 1+d2;
        if(root->right == nullptr) 
            return 1+d1;
        return 1+min(d1,d2);
    }
    //find max
    int maxDepth(TreeNode* root){
        if(root == nullptr) return 0;
        int dleft= maxDepth(root->left);
        int dright= maxDepth(root->right);
        if(root->left == nullptr) 
            return 1+dright;
        if(root->right == nullptr) 
            return 1 + dleft;
        
        return 1+max(dleft, dright);
        
    }
};
