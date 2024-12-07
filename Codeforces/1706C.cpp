#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+5;
int a[N];
void solve(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    int ans1=0,ans2=0;
    if(n%2==1){
        for(int i=2;i<=n;i+=2){
            int d=0;
            if(a[i]<=a[i-1]) d=max(d,a[i-1]-a[i]+1);
            if(a[i]<=a[i+1]) d=max(d,a[i+1]-a[i]+1);
            ans1+=d;
        }
        cout<<ans1<<endl;
    }
    else {
        //从2开始留4个位置
        for(int i=2;i<n-2;i+=2){
            int d=0;
            if(a[i]<=a[i-1]) d=max(d,a[i-1]-a[i]+1);
            if(a[i]<=a[i+1]) d=max(d,a[i+1]-a[i]+1);
            ans1+=d;
        }

        int d1=0,d2=0;
        if(a[n]>=a[n-1]) d1=max(d1,a[n]-a[n-1]+1);
        if(a[n-2]>=a[n-1]) d1=max(d1,a[n-2]-a[n-1]+1);

        if(a[n-1]>=a[n-2]) d2=max(d2,a[n-1]-a[n-2]+1);
        if(a[n-3]>=a[n-2]) d2=max(d2,a[n-3]-a[n-2]+1);
        ans1+=min(d1,d2);

        //从3开始密铺
        for(int i=3;i<=n;i+=2){
            int d=0;
            if(a[i]<=a[i-1]) d=max(d,a[i-1]-a[i]+1);
            if(a[i]<=a[i+1]) d=max(d,a[i+1]-a[i]+1);
            ans2+=d;
        }
        //cout<<ans1<<" "<<ans2<<endl;
        ans1=min(ans1,ans2);
        cout<<ans1<<endl;
    }
}
signed main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}