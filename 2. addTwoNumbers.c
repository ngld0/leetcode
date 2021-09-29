/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    
    struct ListNode* res = (struct ListNode*)malloc(sizeof (struct ListNode)), *cur=res;
    
    int sum;
    
    int car=0 ; 
    
    while(l1||l2){
        sum = (l1?l1->val:0) + (l2?l2->val:0) + car ;
        
        car = sum/10;

        struct ListNode* new_node = (struct ListNode*)malloc(sizeof (struct ListNode));
        
        new_node->val = sum%10;
        
        new_node->next = NULL;
            
        cur->next = new_node;
            
        cur = cur->next;        
        
        if(l1) l1 = l1->next;
        
        if(l2) l2 = l2->next;
    }
    
    if(car) {
        cur->next = (struct ListNode*)malloc (sizeof (struct ListNode));
        cur->next->val = 1;
        cur->next->next = NULL;
    }
    return res->next;
    

}
