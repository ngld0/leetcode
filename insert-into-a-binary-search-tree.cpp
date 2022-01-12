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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        //solve 1. recursive
		// if (!root) {
		// 	TreeNode *add = new TreeNode(val);
		// 	return add;
		// }
		// if (val < root->val) {
		// 	root->left = insertIntoBST(root->left, val);
		// }
		// else {
		// 	root->right = insertIntoBST(root->right, val);
		// }
		// return root;
        // sol 2. Interative
        if(root == NULL) return new TreeNode(val);
	    else{

            TreeNode*curr = root,*tmp = NULL;
            while(curr){

                tmp = curr;

                val < curr->val ? curr = curr->left : curr = curr->right;
            }

            val < tmp->val ? tmp->left = new TreeNode(val) : tmp->right = new TreeNode(val);

            return root; 
	    }
    }
};
