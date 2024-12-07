#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    int n,q;
    cin>>n>>q;
    int a[n+5];
    int f[n+5],s[n+5];
    f[0]=s[0]=0;
    for(int i=1;i<=n;i++) cin>>a[i],s[i]=s[i-1]+a[i],f[i]=f[i-1]^a[i];

    while(q--){
        int l,r;cin>>l>>r;
        cout<<s[r]-s[l-1]-(f[r]^f[l-1])<<endl;
        cin>>l>>r;
         cout<<"## "<<s[r]-s[l-1]-(f[r]^f[l-1])<<endl;
    }

}
signed main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}