#include<bits/stdc++.h>
using namespace std;
const int maxn=4e5+5;
vector< pair<int,int> >e[maxn];
int a[maxn];
typedef long long ll;
void solve(){
    ll n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];

    for(int i=1;i<=n+m;i++) e[i].clear();
    for(int i=1;i<=n;i++){
        e[a[i]].push_back({1,0});
    }
    for(int i=1;i<=m;i++){
        int v,p;
        cin>>v>>p;
        e[a[v]].push_back({-1,i});
        a[v]=p;
        e[a[v]].push_back({1,i});
    }
    ll ans=2*n*(m*(m+1)/2);

    for(int i=1;i<=n;i++){
        e[a[i]].push_back({-1,m+1});
    }

    for(int i=1;i<=n+m;i++){
        ll tmp=0;
        for(int j=1;j<e[i].size();j+=2){
            tmp+=e[i][j].second-e[i][j-1].second;
        }
      //  if(tmp) cout<<i<<" "<<tmp<<endl;
        ans-= (tmp-1)*tmp/2;
    }
    cout<<ans<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}