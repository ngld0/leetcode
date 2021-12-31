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
    //Sol 1. O(n) find max node and min node ancestor
    int helper(TreeNode*root, int a, int b){
        if(!root) return 0;
        a=max(root->val, a);
        b=min(root-> val, b);
        int left = helper(root->left, a, b);
        int right = helper(root->right, a,b);
        return max(a - b, max(left, right));
    }
    int maxAncestorDiff(TreeNode* root) {
        return helper(root, root->val, root->val);    
    }
    // Sol 2. burteforce O(n^2)
};
// same with sol 1
class Solution {
private:
    int ans = 0;
public:
    //O(n)
    void helper(TreeNode*root, int a, int b){
        if(!root) return ;
        a=max(root->val, a);
        b=min(root-> val, b);
        ans = max(a - b,ans);
        helper(root->left, a, b);
        helper(root->right, a,b);
        //ans = max(a - b, max(left, right));
    }
    int maxAncestorDiff(TreeNode* root) {
        helper(root, root->val, root->val);
        return ans;    
    }
    
};
