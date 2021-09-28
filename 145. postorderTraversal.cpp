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
    //Follow up: Recursive solution is trivial, could you do it iteratively?
    
    vector<int> postorderTraversal(TreeNode* root) {
        if(!root) return {};
        vector<int> res;
        stack<TreeNode*> temp{{root}};
        
        while(!temp.empty()){
            
            TreeNode *t = temp.top();
            
            temp.pop();
            
            res.insert(res.begin(), t->val);
            
            if(t->left) temp.push(t->left);            
            if(t->right) temp.push(t->right);

        }
        return res;
    }
// private:
//     void helper(TreeNode* root, vector<int>& res){
       
//         if(!root) return;
//          res.insert(res.begin(), root->val);

//         if(root->left) helper(root->left, res);
        
        
//         if(root->right) helper(root->right, res);

        
//     }
};
/***
Given the root of a binary tree, return the postorder traversal of its nodes' values.

 

Example 1:


Input: root = [1,null,2,3]
Output: [3,2,1]
Example 2:

Input: root = []
Output: []
Example 3:

Input: root = [1]
Output: [1]
Example 4:


Input: root = [1,2]
Output: [2,1]
Example 5:


Input: root = [1,null,2]
Output: [2,1]
 

Constraints:

The number of the nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100
 

Follow up: Recursive solution is trivial, could you do it iteratively?

***/
