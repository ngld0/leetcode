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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *first = head;
        //return begining + k -> first node;
        for(int i = 1;i< k;i++){
            first = first->next;
        }
        ListNode *fast =first->next, *second = head;
        //return second node = end - k;
        while(fast){
            second = second->next;
            fast = fast->next;
        }
        //swap value of two node
        // it is swap value, not exaclty swap node in linked list
        swap(second->val, first->val);
        return head;
    }
};
