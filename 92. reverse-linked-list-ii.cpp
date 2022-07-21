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
         // reversing the nodes in range left-right
        /* Ex: 1-> 2 -> 3 -> 4->5 (left =2,right = 4)
        step1. initialize
        move the pointer to the left node and set it be current node,
        the previous of current are pre node;
        and the next of current node are forward node;
        step2. reversing nodes in range [left,right]
        try to reverse from the left to right node, you can follow the following problem first: https://leetcode.com/problems/reverse-linked-list/
        ~> the following for loop are try to reverse the nodes in range of [left, right]
        1-> 2 <- 3 <- 4->5 (2->5)
        step3. 
        set the head pointer to next and next
        1->4->3->2->5
        
        */
        //step 1;
        ListNode dummy(0);
        dummy.next = head;

        ListNode* h = &dummy;
        for (int i = 1; i <left;i++) 
        {
            h = h->next;
        }
        ListNode* pre = h->next;
        
        ListNode* cur = pre->next;
 
        //step2
        for (int i =0 ; i <right - left;i++){
            ListNode* nex = cur->next; //temporary node to save the node after swap; the saving node are after r node
            //cout << q->val << r->val <<t->val <<endl;
            cur->next = pre; // reversing the direction
            pre = cur; // 
            cur = nex; // set back the node after swap
        }
        // step 3
        h->next->next = cur; // set the next node after reverse
        h->next = pre;
        return dummy.next;
    }
};
