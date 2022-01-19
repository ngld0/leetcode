/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
        ListNode *first = head, * second = head;
        bool ok = false;
        
        while(first != nullptr  && second  != nullptr && second ->next != nullptr ){
            first = first->next;
            second = second->next->next;
            if(first == second){
                ok = true;
                break;
            }
        }
        
        if(!ok){
            
            return nullptr;
        }
        
        first = head;
        while(first != second){
            
            first = first->next;
            second = second->next;
        }
        
        
        return second;
        
    }
};
