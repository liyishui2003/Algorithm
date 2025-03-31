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
    TreeNode* build(vector<int>& preorder,int l,int r,vector<int>& inorder,int L,int R){
        if(l > r || L > R) return nullptr;
        TreeNode* root = new TreeNode(preorder[l]);//根节点
        int index = -1;
        for(int i = L;i <= R;i++){
            if(inorder[i] == preorder[l]) {
                index = i;//找到根节点在当前划分出的区间的哪一个
                break;
            }
        }
        if(l == r) return root;
        int len = index - L;
        root->left = build(preorder,l + 1,l + len,inorder,L,L + len - 1);
        root->right = build(preorder,l + len + 1,r,inorder,L + len + 1,R);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder,0,preorder.size() - 1,inorder,0,inorder.size() - 1);
    }
};
