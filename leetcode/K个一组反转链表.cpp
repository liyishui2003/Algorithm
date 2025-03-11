/**
递归比纯模拟好写太多了。
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
        ListNode *ret = head;
        if(!ret) return head;
        for(int i=0;i<k-1;i++){
            ret= ret->next;
            if(!ret) return head;
        }
        ListNode *cur = head,*pre=nullptr;
        for(int i=0;i<k;i++){
            ListNode *nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
        }
        head->next = reverseKGroup(cur,k);
        return ret;
    }
};
