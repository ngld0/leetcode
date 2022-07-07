/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    // sol1. O(n) space (n); travel all node and put to a string, checking this string is palindrome
    
    //sol 2. challenge O(1) space
    ListNode *reverse(ListNode *root){
        if(!root) return NULL;
        ListNode *pre=NULL;
        ListNode *temp;
        while(root){
            temp=root->next;
            root->next=pre;
            pre=root;
            root=temp;
        }
        return pre;
        
    }
    bool isPalindrome(ListNode* head) {
        if(!head) return true;
         ListNode *slow=head;
        ListNode *fast=head;
        // let's find the middle element of linked list
    
        while(fast->next && fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        slow->next=reverse(slow->next);

        slow =slow->next;
        while(slow){
            if(head->val !=slow->val) return false;
            head=head->next;
            slow=slow->next;
        }
        
        return true;
        
    }
};
