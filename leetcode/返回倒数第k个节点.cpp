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
    ListNode* rev(ListNode* head){
        ListNode* cur = head;
        ListNode* pre = nullptr;
        while(1){
            ListNode* nxt = cur->next;
            cur->next = pre;
            pre = cur;
            if(nxt==nullptr) break;
            else cur = nxt;
        }
        return cur;//这里的cur是头节点
    }
    int kthToLast(ListNode* head, int k) {
        ListNode* Head=rev(head);
        cout<<Head->val<<endl;
        k--;
        while(k--){
            Head=Head->next;
        }
        return Head->val;
    }
};
