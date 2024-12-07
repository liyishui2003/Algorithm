#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int fa[N],id[N],x[N],y[N];
vector<int>up[N],down[N];
void solve(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) {
        fa[i]=id[i]=0;
        up[i].clear();down[i].clear();
    }
    for(int i=1;i<n;i++){
        cin>>x[i]>>y[i];
        fa[y[i]]=x[i];
        id[y[i]]=i;
    }
    for(int i=1;i<n;i++){

        if(x[i]==1) up[1].push_back(y[i]);
        if(i<id[x[i]]) {
            up[x[i]].push_back(y[i]);
        }
        else down[x[i]].push_back(y[i]);
    }
    queue<int>q,p;
    q.push(1);
    int cnt=0,use=0;
    while(cnt<15){
         while(!q.empty()){
            int x=q.front();
            q.pop();
            use++;
            for(auto v:up[x]){
                p.push(v);
                cout<<x<<" 1 "<<v<<endl;
            }
         }  // update up
         cout<<"==="<<use<<endl;
        if(use==n) break;
        cnt++;
        while(!p.empty()){
            int x=p.front();
            p.pop();
            q.push(x);
            for(auto v:down[x]){
                cout<<x<<" 2 "<<v<<endl;
                p.push(v);
            }
        }
    }
    cout<<cnt<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}