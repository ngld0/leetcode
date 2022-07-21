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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode dummy(0);
        dummy.next = head;

        ListNode* cur = &dummy;
        
        for (int i = 1; i <left;i++) 
        {
            cur = cur->next;
        }
        
        ListNode* q = cur->next;
        
        ListNode* r = q->next;
        
        for (int i =0 ; i <right -left;i++){
            ListNode* t = r->next; //temporary node to save the node after swap; the saving node are after r node
            r->next = q; // swap q and r node
            q = r; // using to swap q and r
            r = t; // set back the node after swap
        }

        cur->next->next = r; // set the last node after reverse
        cur->next = q;

        return dummy.next;
    }
};
