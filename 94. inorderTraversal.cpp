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
    
  //Follow up: Recursive solution is trivial, could you do it iteratively  
    vector<int> inorderTraversal(TreeNode* root) {
        //if(!root) return {};
        vector<int> res;
        stack<TreeNode*> st;
        TreeNode *t = root;
        while (!st.empty() || t) {
            if (t) {
                st.push(t);
                t = t->left;
            } else {
                t = st.top(); st.pop();
                res.push_back(t->val);
                t = t->right;
            }
        }
        return res;
    }
//     // recursive
//     vector<int> inorderTraversal(TreeNode* root) {
//         vector<int> res;
        
//         helper(root, res);
        
//         return res;
//     }
    
// private:
//     void helper(TreeNode* root, vector<int>& res){
//         if(!root) return;
//         if(root->left)
//             helper(root->left, res);
        
//         res.push_back(root->val);
//         if(root->right)
//             helper(root->right, res);

        
//     }
// };
/***
Given the root of a binary tree, return the inorder traversal of its nodes' values.

 

Example 1:


Input: root = [1,null,2,3]
Output: [1,3,2]
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
Output: [1,2]
 

Constraints:

The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100

***/
