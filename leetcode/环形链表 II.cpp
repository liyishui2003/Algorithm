/*
参考一个清晰的题解：
slow 指针走的路程 ： a + m*b +c
fast 指针走的路程 ： a + n *b +c
且 fast 走的路程是 slow的两倍，则 2a + 2mb +2c = a + n*b +c   ----> a = (n-2m-1)*b + b -c 
从上述公式，可得知，快慢指针遍历完，可重置一个新的指针，从head开始遍历和slow一起往前走，它们一定会在成环的点相遇
作者：九尾
链接：https://leetcode.cn/problems/c32eOV/solutions/2843190/shuang-zhi-zhen-xun-zhao-huan-xing-lian-7p4my/
*/
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
    ListNode *detectCycle(ListNode *head) {
        if(head == nullptr){
            return nullptr;
        }
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast != nullptr){
            slow = slow->next;
            if(slow == nullptr) return nullptr;
            if(fast->next != nullptr){
                fast = fast->next;
            }
            fast = fast->next;
            if(fast == slow){
                ListNode* ptr = head;
                while(ptr != slow){
                    ptr = ptr->next;
                    slow = slow->next;
                }
                return ptr;
            }
        }
        return nullptr;
    };
};
