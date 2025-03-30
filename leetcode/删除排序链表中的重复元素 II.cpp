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
    void check(ListNode*& head){
        int flag = 0;
        while(head->next && head->next->val == head->val){
                head = head->next;
                flag = 1;
        }
        if(flag) head = head->next;
    }
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *dummy = new ListNode(-105);
        ListNode *pre = dummy;
        while(head != nullptr){
            int flag = 0;
            while(head && head->next && head->next->val == head->val)
                check(head);
            pre->next = head;
            pre = head;
            if(head) head = head->next;
        }
        return dummy->next;
    }
};
