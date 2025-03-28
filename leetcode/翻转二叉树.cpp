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
    TreeNode* invertTree(TreeNode* root) {
        rotate(root);
        return root;
    }
};
