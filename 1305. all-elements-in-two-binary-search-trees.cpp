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
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> vec_r1, vec_r2;
        if (root1) dfs(root1, vec_r1);
        if (root2) dfs(root2, vec_r2);
        int pos1 = 0, pos2 = 0;
        for(int i = 0 ; i < vec_r2.size();i++){
            vec_r1.push_back(vec_r2[i]);
        }
        sort(vec_r1.begin(), vec_r1.end());
        return vec_r1;
    }
    
    void dfs(TreeNode* root, vector<int>& ret)
    {
        if (root->left) dfs(root->left, ret);
        ret.push_back(root->val);
        if (root->right) dfs(root->right, ret);
    }
};
/*
Given two binary search trees root1 and root2, return a list containing all the integers from both trees sorted in ascending order.

 

Example 1:


Input: root1 = [2,1,4], root2 = [1,0,3]
Output: [0,1,1,2,3,4]
Example 2:


Input: root1 = [1,null,8], root2 = [8,1]
Output: [1,1,8,8]
 

Constraints:

The number of nodes in each tree is in the range [0, 5000].
-10^5 <= Node.val <= 10^5
*/
