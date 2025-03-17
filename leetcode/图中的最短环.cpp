typedef pair<int,int> PII;
class Solution {
public:
    int ret = INT_MAX;
    int dis[1005];
    vector<int>e[1005];
    void bfs(int u){
        queue<PII>q;
        q.push(make_pair(u,-1));
        memset(dis,-1,sizeof dis);
        dis[u] = 0;
        while(!q.empty()){
            auto x = q.front();
            q.pop();
            for(auto v:e[x.first]){
                if(dis[v] == -1){
                    dis[v] = dis[x.first] + 1;
                    q.push(make_pair(v,x.first));
                }
                else {
                    if(v == x.second )continue;
                    ret = min(ret,dis[v] + dis[x.first] + 1);
                }
            }
        }
    }
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        /*
        solution1:n遍最短路+次短路，答案为min(两点间最短路+次短路)
        无环的情况就是没有次短路
        solution2:dfs摁着硬跑，时间复杂度存疑
        solution3:枚举起点bfs，如果扩展新节点时发现有个节点被遍历过，说明成环。bfs充分利用了边长为1的性质(前两个没有)
        */
        for(auto v:edges){
            e[v[0]].push_back(v[1]);
            e[v[1]].push_back(v[0]);
        }
        for(int i = 0;i < n;i++){
            bfs(i);
        }
        return ret == INT_MAX ? -1:ret;
    }
};
