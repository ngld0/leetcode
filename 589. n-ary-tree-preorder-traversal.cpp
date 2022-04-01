/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    /*
    // recursive
    vector<int> preorder(Node* root) {
        vector<int> ret;
        traversal(root, ret);
        return ret;
    }

    void traversal(Node* node, vector<int> & ret){
        
        if(node == nullptr) return;
        ret.push_back(node->val);
        for(Node* child : node->children){
            
            traversal(child, ret);
        }
    }
    */
    //interative
    vector<int> preorder(Node* root) {
        vector<int> ret;
        
        if(root == nullptr) return ret;
        stack<Node*> st;
        st.push(root);
        while(!st.empty()){
            Node* node = st.top();
            st.pop();
            ret.push_back(node->val);
            for(int i = node->children.size() -1;i>= 0 ;i--){
                
                if(node->children[i] != nullptr){
                    
                    st.push(node->children[i]);
                }
            }
            
        }
        return ret;
    
    }
};
