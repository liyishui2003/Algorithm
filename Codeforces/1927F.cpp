#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,m,mi,out;
int vis[N],keyp[N];
vector<pair<int,int>>e[N];
stack<int>s;
vector<int>ans;
int flag=0,have=0;
void dfs(int u,int fa){
    vis[u]=1;
    s.push(u);
    for(auto v:e[u]){
        int to=v.first,w=v.second;
        if(flag) return;
        if(to==fa)continue;
        if(vis[to] ) {
            // find
            if(keyp[to] || w<=mi || have ) {
                flag=1;
                out=mi;
                ans.clear();
                while(s.top()!=to){
                    ans.push_back(s.top());
                    s.pop();
                }
                ans.push_back(s.top());
                if(have) {
                    cout<<"aowuwuw"<<" "<<u<<" "<<to<<endl;
                }
                return;
            }
        }
        else {
            if(w<=mi){
                keyp[u]=1;
                have++;
            }
            if(flag) return;
         //   cout<<u<<" to "<<to<<endl;
            dfs(to,u);
            if(keyp[u]) {
                keyp[u]=0;
                have--;
            }
            if(flag) return;
        }
    }
    s.pop();
}
bool check(int x){
    mi=x;
    //cout<<"#x "<<x<<endl;
    for(int i=1;i<=n;i++) vis[i]=0;
    for(int i=1;i<=n;i++){
        if(!vis[i]) {
            while(!s.empty()) s.pop();
            flag=0;
            have=0;
            dfs(i,0);
            if(flag==1) return 1;
        }
    }
    return 0;
}
int w[N];
void solve(){
    cin>>n>>m;
    int cnt=0;
    for(int i=1;i<=n;i++) e[i].clear();
    for(int i=1;i<=m;i++){
        int u,v,k;cin>>u>>v>>k;
        e[v].push_back({u,k});
        e[u].push_back({v,k});
        cnt++;w[cnt]=k;
    }
    sort(w+1,w+cnt+1);
    cnt=unique(w+1,w+cnt+1)-(w+1);
    
    int l=1,r=cnt,Ans;
    while(l<=r){
        int mid=(l+r)>>1;
        if(check(mid)){
            r=mid-1;
            //remenber to copy the ans
            Ans=mid;
        }
        else l=mid+1;
    }

    cout<<Ans<<" "<<ans.size()<<endl;
    for(auto v:ans){
        cout<<v<<" ";
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