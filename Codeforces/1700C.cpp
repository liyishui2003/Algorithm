#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
long long a[N];
void solve(){
    int n;
    cin>>n;
    long long mi=INT_MAX;
    for(int i=1;i<=n;i++) cin>>a[i],mi=min(mi,a[i]);

    long long ans=0,delta=0;
    for(int i=1;i<n;i++){
        ans+=abs(a[i]-a[i+1]);
        if(a[i]>=a[i+1]) delta+=a[i]-a[i+1];
    }
    a[1]-=delta;
    ans+=abs(a[1]);
    cout<<ans<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}