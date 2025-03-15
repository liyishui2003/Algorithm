/*
重编号解决溢出问题
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
    int dis = 1;
    unsigned long long ans = 0;
    map<int,unsigned long long>l;
public:
    void dfs(TreeNode* root,int dep,unsigned long long index){
        if(root == nullptr){
            return;
        }
        dis = max(dis,dep);
        if(l.find(dep) == l.end()) l[dep] = index;
        ans = max(ans,index - l[dep] + 1);
        index = index - l[dep] + 1;
        if(root->left) dfs(root->left,dep + 1,index * 2);
        if(root->right) dfs(root->right,dep + 1,index * 2 + 1);
    }
    int widthOfBinaryTree(TreeNode* root) {
        dfs(root,0,1);
        return ans;
    }
};
