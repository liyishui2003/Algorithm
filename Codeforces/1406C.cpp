#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
// 这份代码默认节点编号从 1 开始，即 i ∈ [1,n]
int siz[N],  // 这个节点的「大小」（所有子树上节点数 + 该节点）
    weight[N],  // 这个节点的「重量」，即所有子树「大小」的最大值
    centroid[2];  // 用于记录树的重心（存的是节点编号）
vector<int>e[N];
int n;
void GetCentroid(int cur, int fa) {  // cur 表示当前节点 (current)
  siz[cur] = 1;
  weight[cur] = 0;
  for (auto to:e[cur]) {
    if (to != fa) {  // e[i].to 表示这条有向边所通向的节点。
      GetCentroid(to, cur);
      siz[cur] += siz[to];
      weight[cur] = max(weight[cur], siz[to]);
    }
  }
  weight[cur] = max(weight[cur], n - siz[cur]);
  if (weight[cur] <= n / 2) {  // 依照树的重心的定义统计
    centroid[centroid[0] != 0] = cur;
  }
}
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++) e[i].clear(),siz[i]=weight[i]=0;
    centroid[0]=centroid[1]=0;
    for(int i=1;i<n;i++){
        int x,y;cin>>x>>y;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    GetCentroid(1,0);
    if(centroid[1]==0){
        cout<<centroid[0]<<" "<<e[centroid[0]][0]<<endl;
        cout<<centroid[0]<<" "<<e[centroid[0]][0]<<endl;
        return;
    }
    else {
        for(auto v:e[centroid[0]]){
            if(v!=centroid[1]){
                cout<<v<<" "<<centroid[0]<<endl;
                cout<<v<<" "<<centroid[1]<<endl;
                return;
            }
        }
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}