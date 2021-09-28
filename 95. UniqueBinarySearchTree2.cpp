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
    vector<TreeNode*> dp[10][10];
    vector<TreeNode*> generateTrees(int n) {
        return Fun(1, n);
    }
    
    vector<TreeNode*> Fun(int start, int end) {
        vector<TreeNode*> res;
        if(start > end) {
            res.push_back(NULL);
            return res;
        }
        if(dp[start][end].size() != 0)
            return dp[start][end];
        for(int i = start; i <= end; i++) {
            vector<TreeNode*> tempLeft = Fun(start, i - 1);
            vector<TreeNode*> tempRight = Fun(i + 1, end);
            
            for(int j = 0; j < tempLeft.size(); j++) {
                for(int k = 0; k < tempRight.size(); k++) {
                    TreeNode* node = new TreeNode(i);
                    node->left = tempLeft[j];
                    node->right = tempRight[k];
                    res.push_back(node);
                }
            }
        }
        dp[start][end] = res;
        return dp[start][end];
    }
};
