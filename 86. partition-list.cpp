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
    ListNode* partition(ListNode* head, int x) {
        //step 1. init dummny node of greater listnode and less listnode and their moving pointer
        ListNode* less = new ListNode(0), *greater = new ListNode(0); //as dummy nodes, save the first pointer of each listnode
        ListNode* left = less, *right = greater; // use left, right pointers to moving and putting the value to each listnode
        //step 2. add node for each initialized listnode
        while(head != nullptr){
            if(head->val >= x){ //checking the node are greater or not
                right->next = head;
                right = right->next;
            }else {
                left->next = head;
                left = left->next;
            }
            head = head->next; // moving head pointer
        }
        //step 3. merging left and right
        left->next = greater->next; // merge left and right listnode
        
        right->next = nullptr;
        return less->next;
    }
};
