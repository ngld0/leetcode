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
    pair<int, int> dfs(TreeNode* root)
    {
        if(root == NULL)
            return make_pair<int, int>(0, 0);
        
        auto left = dfs(root->left);
        auto right = dfs(root->right);
        
        return make_pair<int, int>(max(left.first, left.second) + max(right.first, right.second), left.first + right.first + root->val);
    }
public:
    int rob(TreeNode* root) {
        auto p = dfs(root);
        return max(p.first, p.second);
    }
};
// or
class Solution {
public:
    int max_num=INT_MIN;
public:
    unordered_map<TreeNode*,int> umap;    
    int rob(TreeNode* root) {
        if(root==NULL)return 0;
        if(umap[root])return umap[root];
        int left_max=0;
        int right_max=0;
        if(root->left){
            left_max=rob(root->left->left)+rob(root->left->right);
        }
        if(root->right){
            right_max=rob(root->right->left)+rob(root->right->right);
        }
        return umap[root]=max(root->val+left_max+right_max,rob(root->left)+rob(root->right));

    }
};
/*
The thief has found himself a new place for his thievery again. There is only one entrance to this area, called root.

Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that all houses in this place form a binary tree. It will automatically contact the police if two directly-linked houses were broken into on the same night.

Given the root of the binary tree, return the maximum amount of money the thief can rob without alerting the police.

 

Example 1:


Input: root = [3,2,3,null,3,null,1]
Output: 7
Explanation: Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
Example 2:


Input: root = [3,4,5,1,3,null,1]
Output: 9
Explanation: Maximum amount of money the thief can rob = 4 + 5 = 9.
 

Constraints:

The number of nodes in the tree is in the range [1, 104].
0 <= Node.val <= 104
*/
