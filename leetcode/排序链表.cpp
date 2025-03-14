/*
要求原地排序的话只能用归并排序，基于链表的归并排序就是快慢指针求中间节点+合并两个有序链表
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
    ListNode* HalfNode(ListNode* head){
        ListNode *fast = head,*slow = head;
        while(fast->next!=nullptr && fast->next->next!=nullptr){ //判两次next是为了处理长度为奇/偶的情况
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
    ListNode* sortList(ListNode* head){
        if(head == nullptr){
            return head;
        }
        if(head->next == nullptr){
            return head;
        }
        ListNode* slow = HalfNode(head);
        ListNode* newHead = slow->next;
        slow->next = nullptr;
        return merge(sortList(head),sortList(newHead));
    }
    ListNode* merge(ListNode* l1,ListNode* l2){
        ListNode* dummy = new ListNode(-1);
        ListNode* cur = dummy;
        while(l1 != nullptr || l2 != nullptr){
            if(l1 == nullptr){
                cur->next = l2;
                cur = cur->next;
                l2 = l2->next;
            }
            else if(l2 == nullptr){
                cur->next = l1;
                cur = cur->next;
                l1 = l1->next;
            }
            else if(l1->val < l2->val){
                cur->next = l1;
                cur = cur->next;
                l1 = l1->next;
            }
            else {
                cur->next = l2;
                cur = cur->next;
                l2 = l2->next;
            }
        }
        return dummy->next;
    }
};
