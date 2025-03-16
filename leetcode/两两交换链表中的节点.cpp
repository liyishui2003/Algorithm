/**
K个一组反转链表中K = 2的情况
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == nullptr) return nullptr;
        ListNode *ret = head,*newHead = nullptr;;
        for(int i = 0;i < k - 1;i++){
            ret = ret->next;
            if(ret == nullptr) return head;
        }
        newHead = ret->next;
        ListNode *cur = head,*pre = nullptr;
        for(int i = 0;i < k ;i++){
            ListNode* nxt = cur->next;
            nxt->next = cur;
            pre = cur;
            cur = nxt;
        }
        cur->next = reverseKGroup(newHead,k);
        return ret;
    }
    ListNode* swapPairs(ListNode* head) {
        return reverseKGroup(head,2);
    }
};
