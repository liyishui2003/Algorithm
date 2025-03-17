/*
本解法时间O(N),空间O(N)。
最优解是快慢指针求中间节点+反转链表(后半段)+合并两个链表
*/
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
    int cnt = 0;
    ListNode* reverseList(ListNode* head){
        ListNode *cur = nullptr;
        while(head != nullptr){
            ListNode *pre = cur;
            cur = new ListNode(head->val);
            cur->next = pre;
            cnt ++;
            head = head->next;   
        }
        return cur;
    }
    void reorderList(ListNode* head) {
        ListNode* inv = reverseList(head);
        int order = 0;
        ListNode* dummy = new ListNode(-1);
        ListNode* cur = dummy;
        while(order < cnt){
            if(order & 1){
                dummy->next = inv;
                inv = inv->next;
            }
            else {
                dummy->next = head;
                head = head->next;
            }
            dummy = dummy->next;
            order++;
            if(order == cnt) dummy->next = nullptr;
        }
        head = cur->next;
    }
};
