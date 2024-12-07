#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
#define int long long 
int a[N];
void solve(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(n%2==1){
        cout<<"YES"<<endl;
        return;
    }

    for(int i=2;i<n;i++){
        int d=a[i]-a[i-1];
        if(d>=0){
            a[i]-=d;
            a[i+1]-=d;    
        }
        else {
            a[i]+=abs(d);
            a[i+1]+=abs(d);
        }
    }

    if(a[n-1]<=a[n]) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
signed main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}