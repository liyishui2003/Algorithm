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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *dummy = new ListNode(-1);
        ListNode *ret =dummy,*pre = nullptr;
        dummy->next = head;
        while(dummy != nullptr){
            if(dummy->val == val){
                if(pre != nullptr) {
                    pre->next = dummy->next;
                    dummy = dummy->next;
                }
            }
            else {
                pre = dummy;
                dummy = dummy->next;
            }
        }
        return ret->next;
    }
};
