/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseList(struct ListNode* head){
    struct ListNode* cur = NULL;
    struct ListNode* nex;
    while(head !=NULL){
        nex = head->next;
        head->next = cur;
        cur = head;
        head =nex;
        
        
    }
    return cur;
}
