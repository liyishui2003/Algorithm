/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == nullptr){
            return false;
        }
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast != nullptr){
            slow = slow->next;
            if(slow == nullptr) return false;
            if(fast->next != nullptr){
                fast = fast->next;
            }
            fast = fast->next;
            if(fast == slow){
                return true;
            }
        }
        return false;
    }
};
