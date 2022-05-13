/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        Node* head=root;
        
        Node* prev=nullptr;
        
        Node* curr=nullptr;
        
        while (head!=nullptr){
            curr=head;
            
            prev=nullptr;
            
            head=nullptr;
            
            while (curr!=nullptr){
                if (curr->left != nullptr){
                    
                    if (prev != nullptr)
                        prev->next=curr->left;
                    else 
                        head=curr->left;
                    prev=curr->left;
                }
                if (curr->right != nullptr){
                    if (prev!=nullptr)
                        prev->next=curr->right;
                    else 
                        head=curr->right;
                    prev=curr->right;
                }
                curr=curr->next;
            }
        }
        return root;
    }
};
