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
    int minCameraCover(TreeNode* root) {
        int ans= 0;
        int ret = addCamera(root, ans);
        if(ret == -1){
            ans++;
        }
        return ans;
    }
    // preorder search
    int addCamera(TreeNode* root, int& ans){
        // if the rootnode is null then we dont need to monitor it.
        if(root==nullptr) return 0;
        // checking left node
        int left = addCamera(root->left,  ans);
        // checking right node
        int right = addCamera(root->right,ans);
        //if the left node or right node is not monitored, then we should add a camera to monitor this node and set this node is monitored
        if(left == -1 || right ==-1 ) {
           ans++;
           return 1; 
        }
        // otherwise, if left node or right node be covered then we dont need to monitor this node.
        else if(left == 1||right == 1){
            return 0;
        }
        return -1;
    }
};
