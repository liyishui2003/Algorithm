#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int a[N],v[N];
int n,k,d;
int check(){
    int cnt=0;
    for(int i=1;i<=n;i++) cnt+=(a[i]==i);
    return cnt;
}
void solve(){
    cin>>n>>k>>d;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=k;i++) cin>>v[i];

    long long ans=0;
    int p=1;
    for(int i=1;i<=max(max(k,n),min(d,(int)2e5));i++){
        // 结算算一次
        ans=max(ans,1ll*check()*(d>=i)+(d-(i))/2);
        for(int j=1;j<=v[p];j++) a[j]++;
        p++;
        if(p==k+1) p=1;
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