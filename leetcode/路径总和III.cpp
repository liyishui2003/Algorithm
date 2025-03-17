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
    int tot = 0;
    unordered_map<long long,int>mp;
    /*
    5-8-4-5
    4-11-7
    5-4-11-2
    */
    void dfs(TreeNode* u,long long sum,int targetSum){
        if( u == nullptr){
            return ;
        }
        sum += u->val;
        tot += mp[sum - targetSum];
        mp[sum] ++;
        if(u->left) dfs(u->left,sum,targetSum);
        if(u->right) dfs(u->right,sum,targetSum);
        mp[sum] --;
    }
    int pathSum(TreeNode* root, int targetSum) {
        mp[0] = 1;
        dfs(root,0,targetSum);
        return tot;
    }
};
