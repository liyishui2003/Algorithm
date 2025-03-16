/*
一顿操作猛如虎，一看击败百分五。
加个剪枝，记录当前前缀和，就百分百了。
*/
class Solution {
public:
    vector<string> ret;
    int use[20];
    void dfs(int u,int n,int sum){
        if(sum < 0) return;
        if(u == n){
            if(sum != 0) return;
            int l = 0;
            string tmp = "";
            for(int i = 0;i < n;i++){
                tmp.push_back(use[i] == -1 ? ')' : '(') ;
            }
            ret.push_back(tmp);
            return;
        }
        use[u] = -1;
        dfs(u + 1,n,sum + use[u]);
        use[u] = 1;
        dfs(u + 1,n,sum + use[u]);
    }
    vector<string> generateParenthesis(int n) {
        dfs(0,n * 2,0);
        return ret;
    }
};
