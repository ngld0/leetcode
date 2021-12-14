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
//sol 1. binary tree, left node smaller than root, right node bigger than root
class Solution {
public:
    int sum = 0;
    int rangeSumBST(TreeNode* root, int low, int high) {
        helper(root, low, high);
        return sum;
    }
    void helper(TreeNode* root, int low, int high){
        
        if(root==NULL) return ;
        if(root->val >= low && root->val <= high){
            
            helper(root->left, low, high);
            sum+= root->val;
            helper(root->right, low, high);
        }else if(root->val > high){
            helper(root->left, low, high);
        }else if(root->val < low){
            
            helper(root->right, low, high);
        }
    }
};
//sol 2. using queue
class Solution
{
public:
    int rangeSumBST(TreeNode *root, int low, int high)
    {
        int sum = 0;
        if (root == NULL)
            return sum;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            int n = q.size();
            for (int i = 0; i < n; i++)
            {
                TreeNode *curr = q.front();
                q.pop();
                if (curr != NULL and (curr->val <= high and curr->val >= low))
                {
                    sum += curr->val;
                }
                if (curr->left != NULL)
                    q.push(curr->left);
                if (curr->right != NULL)
                    q.push(curr->right);
            }
        }
        return sum;
    }
};
/*
Given the root node of a binary search tree and two integers low and high, return the sum of values of all nodes with a value in the inclusive range [low, high].

 

Example 1:


Input: root = [10,5,15,3,7,null,18], low = 7, high = 15
Output: 32
Explanation: Nodes 7, 10, and 15 are in the range [7, 15]. 7 + 10 + 15 = 32.
Example 2:


Input: root = [10,5,15,3,7,13,18,1,null,6], low = 6, high = 10
Output: 23
Explanation: Nodes 6, 7, and 10 are in the range [6, 10]. 6 + 7 + 10 = 23.
 

Constraints:

The number of nodes in the tree is in the range [1, 2 * 104].
1 <= Node.val <= 105
1 <= low <= high <= 105
All Node.val are unique.
*/
