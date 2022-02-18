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
    int pairSum(ListNode* head) {
        
        vector<int> v;
    
        while (head != nullptr){
            v.push_back(head->val);
            head = head->next;
        }
        int i =0, j = v.size() - 1, ret = v[i] + v[j];
        while(i<j){
            ret = max(ret, v[i] + v[j]);
            i++;
            j--;
        }
        return ret;
        
    }
};
