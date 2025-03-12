//想半天怎么原地交换，结果是交换值
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
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*>q;
        q.emplace(root);
        bool isOdd = false;
        while(!q.empty()){
            int sz = q.size();
            vector<TreeNode*>arr;
            for(int i = 0;i < sz;i++){
                TreeNode* node = q.front();
                q.pop();
                if(isOdd){
                    arr.emplace_back(node);
                }
                if(node->left){
                    q.emplace(node->left);
                    q.emplace(node->right);//完美二叉树所以可以直接加右孩子
                }
            }
            if(isOdd){
                for(int l = 0,r = sz - 1;l<r;l++,r--){
                    swap(arr[l]->val,arr[r]->val);
                }
            }
            isOdd ^= true;
        }
        return root;
    }
};
