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
    
    //recursive
    vector<int> postorder(Node* root) {
        vector<int> ret;
        traversal(root,ret);
        return ret;     
    }
    
    
    void traversal(Node* root, vector<int> &ret){
        
        if(root == nullptr) return;
        for(Node* child: root->children){
            traversal(child, ret);
        }
        ret.push_back(root->val);
    }
    
    /*
    //iterative
    fail test case []
    vector<int> postorder(Node* root) {
       vector<int> ret;

        if(root == nullptr) {};
        stack<Node*> st;
        Node* last = nullptr;
        st.push(root);
        while(!st.empty()){
            Node* node = st.top();
            auto& child = node->children;
            if(!child.empty() && last != child.back()){
                for(int i = node->children.size()-1;i>=0  ;i--){

                    if(node->children[i] != nullptr){
                        st.push(node->children[i]);
                    }
                }
            }

            else {
                ret.push_back(node->val);
                st.pop();
                last = node;
            }
        }
        
        return ret;
        
    }
    */
};
