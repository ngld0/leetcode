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
// Sol_1
class Solution {
public:
    void reorderList(ListNode* head) {
        if(!head->next)
            return;
        
        ListNode *p1 = head, *p2 = head;
        while(p2 && p2->next) {
            p1 = p1->next;
            p2 = p2->next->next;
        }
        
        stack<ListNode*> nodes;
        p2 = p1->next;
        while(p2) {
            nodes.push(p2);
            p2 = p2->next;
        }
        
        p1->next = nullptr;
        p1 = head;
        while(!nodes.empty()) {
            nodes.top()->next = p1->next;
            p1->next = nodes.top();
            p1 = nodes.top()->next;
            nodes.pop();
        }
    }
};
// Sol_2
class Solution {
public:
    // O(N) time, O(1) space in total
    void reorderList(ListNode *head) {
        if (!head || !head->next) return;

        // find the middle node: O(n)
        ListNode *p1 = head, *p2 = head->next;
        while (p2 && p2->next) {
            p1 = p1->next;
            p2 = p2->next->next;
        }

        // cut from the middle and reverse the second half: O(n)
        ListNode *head2 = p1->next;
        p1->next = NULL;

        p2 = head2->next;
        head2->next = NULL;
        while (p2) {
            p1 = p2->next;
            p2->next = head2;
            head2 = p2;
            p2 = p1;
        }

        // merge two lists: O(n)
        for (p1 = head, p2 = head2; p1; ) {
            auto t = p1->next;
            p1 = p1->next = p2;
            p2 = t;
        }

        
    }
};
/*
You are given the head of a singly linked-list. The list can be represented as:

L0 → L1 → … → Ln - 1 → Ln
Reorder the list to be on the following form:

L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
You may not modify the values in the list's nodes. Only nodes themselves may be changed.

 

Example 1:


Input: head = [1,2,3,4]
Output: [1,4,2,3]
Example 2:


Input: head = [1,2,3,4,5]
Output: [1,5,2,4,3]
 

Constraints:

The number of nodes in the list is in the range [1, 5 * 104].
1 <= Node.val <= 1000
*/
