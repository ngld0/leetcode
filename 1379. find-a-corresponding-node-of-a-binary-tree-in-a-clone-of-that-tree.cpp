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
private: 
    TreeNode* ret;
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if (cloned == nullptr) 
            return cloned;
        if(cloned->val == target->val)
            ret =  cloned;
        
        getTargetCopy (original->left,cloned->left, target);  
        
        getTargetCopy (original->right,cloned->right, target);    
        return ret;
    }
};
