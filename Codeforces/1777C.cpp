#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int a[N],vis[N],book[N];
vector<int>e[N];
void solve(){
    int n,m;
    cin>>n>>m;
    int mx=-1;
    for(int i=1;i<=n;i++) cin>>a[i],mx=max(mx,a[i]);

    for(int i=1;i<=mx;i++) book[i]=0,e[i].clear();
    for(int i=1;i<=n;i++) book[a[i]]=1;

    for(int i=1;i<=m;i++) vis[i]=0;

    for(int i=m;i>=1;i--){
        if(vis[i]) continue;
        for(int j=2;j<=sqrt(i);j++){
            if(i%j==0){
                vis[j]=vis[i/j]=1;
            }
        }
        if(i!=1) vis[1]=1;
    }

    int need=0;
    for(int i=1;i<=m;i++){
        if(vis[i]) continue;
        need++;
        for(int j=1;j*i<=mx;j++){
            if(book[j*i]){
                e[j*i].push_back(i);
            }
        }
    }

    int r=1,cnt=0;
    map<int,int>use;
    int ans=INT_MAX;
    for(int i=1;i<=mx;i++){
        while(cnt<need&&r<=mx){
            for(auto v:e[r]){
                use[v]++;
                if(use[v]==1) cnt++;
            }
            r++;
        }
       // cout<<i<<" ## "<<r<<" "<<cnt<<" "<<need<<endl;
        if(cnt==need) {
            ans=min(ans,r-i-1);  
        }
        for(auto v:e[i]){
            use[v]--;
            if(use[v]==0) {
                cnt--;
            //    cout<<i<<" #"<<v<<" "<<cnt<<endl;
            }
        }
    }
    if(ans==INT_MAX) cout<<-1<<endl;
    else cout<<ans<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}