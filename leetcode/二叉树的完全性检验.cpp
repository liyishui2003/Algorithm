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
    bool isCompleteTree(TreeNode* root) {
        vector<int>ret;
        queue<TreeNode*>q;
        if(root==nullptr) return true;
        q.push(root);
        int dep = 0;
        while(!q.empty()){
            deque<int>p;
            int sz = q.size();
            int pos = INT_MAX,posHave = 0;
            for(int i=0;i<sz;i++){
                auto v=q.front();
                q.pop();
                if(v->left!=nullptr){
                    q.push(v->left);
                }
                if(v->right!=nullptr){
                    q.push(v->right);
                }
                if(v->left == nullptr && v->right != nullptr) {
                    return false;
                }
                if(v->left == nullptr || v->right == nullptr){
                    if(pos == INT_MAX) pos = i;
                }
                if(v->left != nullptr || v->right != nullptr){
                    posHave = i;
                }
            }
            ret.push_back(sz);
            dep++;
            if(posHave > pos) {
                return false;
            }
        }
        for(int i = 0;i <ret.size();i++){
            if(ret[i] != (1<<i) && i != ret.size() - 1) return false;
        }
        return true;
    }
};
