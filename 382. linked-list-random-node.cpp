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
// my solution but run time and space are too slow, you can ref to next solution
class Solution {
    private:
        ListNode* head;
public:
    Solution(ListNode* head) {
        this->head= head;
    }
    int getRandom() {
        
        ListNode *cur = head;
        vector<int> v;
        int n;
        for(n = 0; cur != nullptr;n++){
            v.push_back(cur->val);
            cur = cur->next;
        }
        return v[rand()%n];
        
    }
};
//
class Solution {
private:
   ListNode *list; 
public:
    Solution(ListNode* head) {
        list = head;
        srand(time(NULL));
    }
    int getRandom() {
        ListNode *p = list;
        int cnt = 0;
        int res = p->val;
        while (p != nullptr) {
            ++cnt;
            if (rand() % cnt == 0) {
                res = p->val;
            }
            p = p->next;
        }
        return res;
    }

};
/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
