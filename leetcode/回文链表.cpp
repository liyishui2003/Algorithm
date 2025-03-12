//快慢指针求中间节点+链表反转
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
    ListNode* Reverse(ListNode* head){
        if(head == nullptr){
            return nullptr;
        }
        ListNode *cur = head,*pre = nullptr;
        while(1){
            ListNode *nxt = cur->next;
            cur->next = pre;
            pre = cur;
            if(nxt == nullptr) break;
            cur =nxt;
        }
        return cur;
    }
    ListNode* HalfNode(ListNode* head){
        ListNode *fast = head,*slow = head;
        while(fast->next!=nullptr && fast->next->next!=nullptr){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
    bool isPalindrome(ListNode* head) {
        if(head == nullptr) return true;
        ListNode *HalfHead = HalfNode(head);
        ListNode *invHalfHead = Reverse(HalfHead);
        while(head != nullptr){
            if(head->val != invHalfHead->val){
                return false;
            }
            head = head->next;
            invHalfHead = invHalfHead->next;
        }
        return true;
    }
};
