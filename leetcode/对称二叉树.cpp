/*
镜像的定义是反转后相同，先反转，再逐一比对。
*/
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
    void rotate(TreeNode* u){
        if(u == nullptr) return;
        rotate(u->left);
        rotate(u->right);
        swap(u->left,u->right);
    }
    bool checkSame(TreeNode* l,TreeNode* r){
        if(l == nullptr && r == nullptr) return true;
        if(l == nullptr || r == nullptr) return false;
        if(l->val != r->val) return false;
        int checkL = checkSame(l->left,r->left);
        if(checkL == false) return false;
        int checkR = checkSame(l->right,r->right);
        if(checkR == false) return false;
        return true;
    }
    bool isSymmetric(TreeNode* root) {
        rotate(root->left);
        return checkSame(root->left,root->right);
    }
};
