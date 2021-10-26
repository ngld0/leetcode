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
//recursive
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        
        if(!root) return NULL;
        
        TreeNode* temp = root -> left;
        
        root->left = invertTree(root->right);
        
        root->right = invertTree(temp);
        
        return root;
        
        
    }
};

//Iterative
//BFS
```
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL)
            return root;
        else{
            queue<TreeNode*>q;
            q.push(root);
            while(!q.empty()){
                TreeNode* tmp=q.front();
                q.pop();
                swap(tmp->left, tmp->right);
                if(tmp->left)
                    q.push(tmp->left);
                if(tmp->right)
                    q.push(tmp->right);
            }
        }
        return root;
    }
};
```

//DFS
```
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL)
            return root;
        else{
            stack<TreeNode*>s;
            s.push(root);
            while(!s.empty()){
                TreeNode* tmp=s.top();
                s.pop();
                swap(tmp->left, tmp->right);
                if(tmp->left)
                    s.push(tmp->left);
                if(tmp->right)
                    s.push(tmp->right);
            }
        }
        return root;
    }
};
```


/***
// 
Given the root of a binary tree, invert the tree, and return its root.

 

Example 1:


Input: root = [4,2,7,1,3,6,9]
Output: [4,7,2,9,6,3,1]
Example 2:


Input: root = [2,1,3]
Output: [2,3,1]
Example 3:

Input: root = []
Output: []

***/
