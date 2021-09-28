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
static const auto speedup = [](){
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    return NULL;
}();

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* cur = NULL, * nex ;

        while(head){
            nex = head->next;
            head->next = cur;
            cur = head;
            head =nex;
        }
        return cur;
    }
};
