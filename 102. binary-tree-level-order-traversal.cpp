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
    
    vector<vector<int>> ans;
    
    void preorder(TreeNode* root,int lv){
        
        if(ans.size() <= lv){
            
            vector<int> temp{root->val};
            
            ans.push_back(temp);
        }
        else{
            ans[lv].push_back(root->val);
        }
    
        if(root->left)
            preorder(root->left,lv +1);
        
        if(root->right)
            preorder(root->right,lv+1);
        
    }
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == nullptr) return {};
        preorder(root, 0);
        return ans;
    }
};
