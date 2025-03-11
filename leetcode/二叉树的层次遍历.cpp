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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ret;
        queue<TreeNode*>q;
        if(root==nullptr) return ret;
        q.push(root);
        while(!q.empty()){
            deque<int>p;
            int sz = q.size();
            for(int i=0;i<sz;i++){
                auto v=q.front();
                q.pop();
                p.push_back(v->val);
                if(v->left!=nullptr){
                    q.push(v->left);
                }
                if(v->right!=nullptr){
                    q.push(v->right);
                }
            }
            ret.push_back(vector<int>{p.begin(),p.end()});
        }
        return ret;
    }
};
