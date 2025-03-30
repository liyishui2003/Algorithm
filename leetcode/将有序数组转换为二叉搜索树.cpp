/*
观察到平衡二叉搜索树这个结构到处都是，考虑用dfs来递归处理这样的子问题。
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
    TreeNode* toBST(vector<int>& nums,int l,int r){
        if(l > r) return nullptr;
        int len = (r - l + 1) / 2;
        int mid =l + len;
        TreeNode* root = new TreeNode(nums[mid]);
        //cout<<"[l,r]: "<<l<<" "<<r<<" "<<"mid="<<mid<<" nums[mid]:"<<nums[mid]<<'\n'; 
        if(l == r) return root;
        root->left = toBST(nums,l,mid - 1);
        root->right = toBST(nums,mid + 1,r);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        return toBST(nums,0,n - 1);
    }
};
