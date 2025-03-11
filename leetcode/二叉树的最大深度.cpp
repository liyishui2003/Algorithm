//dfs或者bfs都行
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
    int d=0;
    void dfs(TreeNode* u,int dis){
        if(u==nullptr) {
            return;
        }
        d=max(d,dis);
        dfs(u->left,dis+1);
        dfs(u->right,dis+1);
    }
public:
    int maxDepth(TreeNode* root) {
        dfs(root,1);
        return d;
    }
};
