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
//写法1，改变next
ListNode* rev(ListNode* head){
        ListNode* cur = head;
        if(head==nullptr) return head;
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
//写法2，新建节点
ListNode* reverseList(ListNode* head) {
    ListNode* cur = nullptr;
    ListNode* ret = nullptr;
    while(head != nullptr){
        ListNode* tmp = cur;
        cur = new ListNode(head->val);
        cur->next = tmp;
        head=head->next;
    }
    return cur;
}

