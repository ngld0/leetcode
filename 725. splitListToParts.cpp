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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> res(k);
        int len = 0;
        for(ListNode* i = head; i ; i =i->next) len++;
        
        int avg = len /k;
        int ext = len %k;
        
        
        for (int i = 0; i < k && head; i++) {
            int j = 1;
            res[i]=head;
            while(j<avg +(i < ext)){
                head = head->next;
                j++;
            }

            ListNode *tem = head->next;
            
            head->next = NULL;
            
            head = tem;
            
        }
        return res;
        
    }
};
