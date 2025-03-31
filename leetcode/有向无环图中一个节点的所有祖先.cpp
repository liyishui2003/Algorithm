const int N = 1005;
class Solution {
public:
    set<int>ans[N];
    vector<int>edge[N],arr[N];
    int vis[N];
    void dfs(int u){
        if(vis[u]) return;
        vis[u] = 1;
        for(auto v:edge[u]){
            dfs(v);
            ans[u].insert(v);
            for(auto to:ans[v]){
                ans[u].insert(to);
            }
        }
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        //初始化
        for(int i = 0;i < n ;i++) vis[i] = 0,ans[i].clear(),arr[i].clear();
        //建边
        for(auto v:edges){
            edge[v[1]].push_back(v[0]);
        }
        //记忆化搜索
        vector<vector<int>>ret;
        for(int i = 0;i < n;i++){
            dfs(i);
        }
        for(int i = 0;i < n;i++){
            vector<int>add;
            for(auto v:ans[i]){
                add.push_back(v);
            }
            ret.push_back(add);
        }
        return ret;
    }
};
