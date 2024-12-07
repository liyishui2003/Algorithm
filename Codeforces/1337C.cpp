#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+5;
int n,k,siz[N];
vector<int>e[N];
priority_queue<int>q;
void dfs(int u,int fa){
    siz[u]=1;
    for(auto v:e[u]){
        if(v==fa) continue;
        dfs(v,u);
        siz[u]+=siz[v];
    }
    cout<<u<<" "<<siz[u]<<endl;
    q.push(siz[u]);
}
signed main(){
    cin>>n>>k;
    k=n-k;
    for(int i=1;i<=n-1;i++){
        int u,v;cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1,0);
    int ans=0;
    while(k){
        auto x=q.top();q.pop();
        ans+=x-1;
        cout<<x<<endl;
        k--;
    }
    cout<<ans;
}