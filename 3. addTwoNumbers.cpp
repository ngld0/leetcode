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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int car = 0, sum = 0;
        ListNode* res = new ListNode(-1);
        ListNode *now =res;
        while(l1 || l2){
            sum = (l1?l1->val:0) + (l2?l2->val:0) + car ;
            car = sum/10;
            now->next = new ListNode(sum %10);
            now = now->next;
            if(l1) l1=l1->next;
            if(l2) l2=l2->next;
        }
        if(car) now->next = new ListNode(1);
        return res->next;
    }
};
