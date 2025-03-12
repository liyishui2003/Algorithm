//快慢指针，快指针走到结尾时，慢指针走到倒数第N个节点，同时记录一下pre，然后是常规的链表删除操作。
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *fast = head,*slow = head,*pre = nullptr;
        if(head->next == nullptr){
            return nullptr;
        }
        int k = n;
        while(k--){
            fast = fast->next;
        }
        while(fast != nullptr){
            fast = fast->next;
            pre = slow;
            slow = slow->next;
        }
        if(pre == nullptr){
            return head->next;
        }
        // now slow at inv Nth node
        pre->next = slow->next;//delete slow
        return head;
    }
};
