#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int fa[N];
struct node{
    int u,v,w;
}e[N];
bool cmp(node a,node b){
    return a.w>b.w;
}
int find(int u){
    if(fa[u]!=u) return fa[u]=find(fa[u]);
    else return u;
}
int vis[N];
stack<int>s;
vector<int>ans;
int sta,End;
vector<int>v[N];
void dfs(int u,int step){
    if(ans.size()) return;
    s.push(u);
    if(u==End){
        ans.clear();
        while(!s.empty()){
            int x=s.top();
            s.pop();
            ans.push_back(x);
        }
        return;
    }
    vis[u]=1;
    for(auto g:v[u]){
        int to=g;
        if(step==1&&to==End) continue;
        if(vis[to]){
            continue;
        }
        else {
            dfs(to,step+1);
            if(ans.size()) return;
        }
    }
    s.pop();
}
void solve(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) fa[i]=i,v[i].clear(),vis[i]=0;
    for(int i=1;i<=m;i++){
        int x,y,w;cin>>x>>y>>w;
        e[i]=(node){x,y,w};
        v[x].push_back(y);
        v[y].push_back(x);
    }
    sort(e+1,e+m+1,cmp);
    node tmp;
    for(int i=1;i<=m;i++){
        int f1=find(e[i].u),f2=find(e[i].v);
        if(f1==f2) {
            tmp=e[i];
        }
        else {
            fa[f1]=f2;
        }
    }
    while(!s.empty()) s.pop();
    ans.clear();
    sta=tmp.u,End=tmp.v;
    dfs(tmp.u,1);
    cout<<tmp.w<<" "<<ans.size()<<endl;
    for(auto to:ans){
        cout<<to<<" ";
    }
    cout<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}