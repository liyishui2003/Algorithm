#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+5;
vector<int>e[N];
int g[N],f[N],siz[N];
void dfs2(int u,int fa){
     siz[u]++;
    int cnt=0,b[3]={0};
    for(auto to:e[u]){
        if(to==fa) continue;
        dfs2(to,u);
        b[++cnt]=to;
        siz[u]+=siz[to];
    }

    if(cnt==1){
        f[u]=siz[b[1]];
    }
    else {
        f[u]=max( f[b[1]] + siz[b[2]], f[b[2]] + siz[b[1]] );
    }
}
void dfs(int u,int fa){
    int cnt=0,b[3]={0};
    for(auto to:e[u]){
        if(to==fa) continue;
        dfs(to,u);
        b[++cnt]=to;
    }
    if(cnt==1) g[u]=siz[b[1]]-1;
    else if(cnt==2){
        g[u]=max( g[b[1]]+siz[b[2]]-1,g[b[2]]+siz[b[1]]-1 );
    }
   // cout<<u<<" :"<<g[u]<<" "<<siz[u]<<endl;
}
void solve(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) e[i].clear(),g[i]=0,siz[i]=0,f[i]=0;
    for(int i=1;i<n;i++){
        int u,v;cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs2(1,-1);
    dfs(1,-1);
    cout<<g[1]<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}