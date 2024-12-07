#include<bits/stdc++.h>;
using namespace std;
#define int long long
const int N=1e6+5;
int a[N],sum[N];
void solve(){
    int n;cin>>n;
    int ans=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        ans+=a[i]*i;
    }
    sum[n+1]=0;
    for(int i=n;i>=1;i--) sum[i]=sum[i+1]+a[i];

    int combine=0;
    int base=a[1];
    
    for(int i=1;i<n;i++){
        int tmp=ans-(base*(i-combine)+a[i+1]*(i+1-combine))+
        (base+a[i+1])*(i-combine)-sum[i+2];
        if(tmp>ans){
            ans=tmp;
            combine++;
            base+=a[i+1];
        }
        else {
            base=a[i+1];
        }
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