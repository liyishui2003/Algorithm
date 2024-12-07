#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    int n,m,k;
    cin>>n>>m>>k;
    if(k>=4){
        cout<<0<<endl;
        return;
    }
    if(k==1){
        cout<<1<<endl;
        return;
    }
    if(k==2){
        cout<<min(n-1,m)+(m/n)<<endl;
        return;
    }
    else cout<<m-( min(n-1,m)+(m/n) )<<endl;
}
signed main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}