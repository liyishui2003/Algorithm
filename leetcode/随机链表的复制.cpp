/*
也不知道我在写什么，感觉有点抽象。官方解法放在最下面
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node *pre = NULL,*cur = NULL,*ret = NULL;
        Node *copyHead = head;
        unordered_map<Node*,int>index;
        unordered_map<int,Node*>f;
        while(head != NULL){
            index[head] = index.size();
            cur = new Node(head->val);
            f[f.size()] = cur;
            if(pre == NULL){
                ret = cur;
            }
            else {
                pre->next = cur;
            }
            pre = cur;
            head = head->next;
        }
        Node *copyRet = ret;
        while(copyHead != NULL){
            if(copyHead->random == NULL) copyRet->random = NULL;
            else copyRet->random = f[index[copyHead->random]];
            copyHead = copyHead->next;
            copyRet = copyRet->next;
        }
        return ret;
    }
};

/*
官解相当于用哈希表建立起旧链表节点和copy链表节点间一一映射的关系
直接根据next和random的顺序去新建节点，同时哈希表起到去重的作用
*/
class Solution {
public:
    unordered_map<Node*, Node*> cachedNode;

    Node* copyRandomList(Node* head) {
        if (head == nullptr) {
            return nullptr;
        }
        if (!cachedNode.count(head)) {
            Node* headNew = new Node(head->val);
            cachedNode[head] = headNew;
            headNew->next = copyRandomList(head->next);
            headNew->random = copyRandomList(head->random);
        }
        return cachedNode[head];
    }
};
