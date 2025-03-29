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
    map<TreeNode*,int> dis;
    int ans = 0;
    int dfs(TreeNode* root){
        if(root == nullptr) 0;
        int tot = 0,dis = 0;
        if(root->left) {
            int lval = dfs(root->left);
            tot += lval + 1;
            dis = max(dis , lval + 1);
        }
        if(root->right){
            int rval = dfs(root->right);
            tot += rval + 1;
            dis = max(dis , rval + 1);
        }
        ans = max(ans, tot);
        //cout<<root->val<<" "<<dis<<" "<<tot<<endl;
        return dis;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        ans = 0;
        dfs(root);
        return ans;
    }
};
