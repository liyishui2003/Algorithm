#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
const int mod=1e9+7;
int a[N],b[N];
typedef long long ll;
void solve(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];

    sort(a+1,a+n+1);
    sort(b+1,b+n+1);

    ll last=upper_bound(a+1,a+n+1,b[n])-a,ans;
    ll base=n-last+1;
    ans=base;
    for(int i=n-1;i>=1;i--){
        int id=upper_bound(a+1,a+n+1,b[i])-a;
        ll add=last-id;
        if(base-1+add<=0) ans=0;
        ans=ans*(base-1+add)%mod;
        base+=add-1;
        last=id;
    }
    cout<<ans<<endl;
}
signed main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}