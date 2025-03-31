/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* deepSearch(TreeNode* root,TreeNode* pre){
        if(root == nullptr) return nullptr;
        auto *lChild = root->left,*rChild = root->right;//这里要先记住，否则root会作为下一次的pre
        //root的lChild和rChild会被更改
        if(nullptr != pre){
            pre->right = root;
            pre->left = nullptr;
        }
        //函数返回的应该是子树先序遍历里的最后一个节点
        TreeNode* Llast = deepSearch(lChild,root);
        TreeNode* Rlast = deepSearch(rChild,Llast);
        if(Rlast == nullptr){
            if(Llast == nullptr) return root;
            else return Llast;
        }
        else return Rlast;
    }
    void flatten(TreeNode* root) {
        deepSearch(root,nullptr);
    }
};
