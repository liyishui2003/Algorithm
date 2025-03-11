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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* head = list1;
        for(int i=0;i<a-1;i++){
            head=head->next;
        }
        //now head at a-1
        ListNode* nxt1 = head->next;//这里不能直接nxt1=head，否则后面改了head->next
        //会导致nxt1也沿着修改完的链表走
        head->next=list2;
        ListNode* nxt2 = list2;
        for(int i=1;i<=b-a+1;i++){
            nxt1 = nxt1->next;
        }
        while(nxt2->next!=nullptr){
            nxt2 = nxt2->next;
        }
        nxt2->next = nxt1;
        return list1;
    }
};
