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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto cmp = [](const ListNode* a,ListNode* b){
            return a->val > b->val;
        };

        priority_queue<ListNode*,vector<ListNode*>,decltype(cmp)>q;

        for(auto head:lists){
            if(head) q.push(head);
        }

        ListNode* head=nullptr;
        ListNode* cur=nullptr;
        while(!q.empty()){
            auto u=q.top();
            q.pop();
            if(head==nullptr){
                cur=u;
                head=cur;
            }
            else {
                cur->next=u;
                cur=cur->next;
            }
            if(u->next){
                q.push(u->next);
            }
        }
        return head;
    }
};
