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
    void printn(ListNode* head){
        while(head != nullptr){
            cout<<head->val;
            head = head->next;
        }
        cout<<endl;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode dummy(0);
        dummy.next = head;

        ListNode* h = &dummy;
        
        for (int i = 1; i <left;i++) 
        {
            h = h->next;
        }

        ListNode* pre = h->next;
        
        ListNode* cur = pre->next;
        // reversing the nodes in range left-right
        for (int i =0 ; i <right -left;i++){
            ListNode* nex = cur->next; //temporary node to save the node after swap; the saving node are after r node
            //cout << q->val << r->val <<t->val <<endl;
            cur->next = pre; // reversing the direction
            pre = cur; // 
            cur = nex; // set back the node after swap
        }
        // after reversing, set the reversed sub list nodes to the parent listnode
        h->next->next = cur; // set the last node after reverse
        h->next = pre;
        return dummy.next;
    }
};
