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
    // SOl by: Time O(n^2); space O(n);
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if(root == nullptr) 
            return res;
        queue<TreeNode*> que; // Space O(n)
        que.push(root);
        while(que.empty() != 1){ // Time O(n)
            int qsize = que.size();
            for(int i = 0;i < qsize;i++){ // Time O(n)
                TreeNode* node = que.front();
                que.pop();
                if(node->left != nullptr){
                    que.push(node->left);
                }
                if(node->right != nullptr){
                    que.push(node->right);
                }
                if(i == qsize-1){
                    res.push_back(node->val);
                }
            }
        }
        return res;
            
    }
};
