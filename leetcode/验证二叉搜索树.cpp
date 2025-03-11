//动态规划做法
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
    map<TreeNode*,int>mi,mx;
    bool isValidBST(TreeNode* root) {
        bool validL=true,validR=true;
        mi[root]=mx[root]=root->val;
        if(root->left){
            validL = isValidBST(root->left);
            validL = validL & (mx[root->left] < root->val);   
            mi[root] = min(mi[root],mi[root->left]); 
            mx[root] = max(mx[root],mx[root->left]);
        }
        if(root->right){
            validR = isValidBST(root->right);
            validR = validR & (mi[root->right] > root->val);
            mi[root] = min(mi[root],mi[root->right]); 
            mx[root] = max(mx[root],mx[root->right]);
        }
        return validL & validR;
    }
};
//直接在递归时不断缩小区间，不用记录那么多额外的信息
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
    bool dfs(TreeNode* u,long mx,long mi){
        if(u==nullptr){
            return true;
        }
        bool lef = dfs(u->left,u->val,mi);
        bool rig = dfs(u->right,mx,u->val);
        if(u->val>=mx || u->val<=mi){
            return false;
        }
        return lef & rig;
    }
    bool isValidBST(TreeNode* root) {
        return dfs(root,LONG_MAX,LONG_MIN);
    }
};
//也可以考虑中序遍历，要求中序遍历得到的数组是递增的
