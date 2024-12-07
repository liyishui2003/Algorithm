#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+5;
int a[N];
void solve(){
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(k>=3){
        cout<<0<<endl;
        return;
    }

    sort(a+1,a+n+1);
    int d=LONG_LONG_MAX;
    for(int i=1;i<n;i++){
        d=min(d,a[i+1]-a[i]);
        d=min(d,min(a[i],a[i+1]));
    }

    if(k==1){
        cout<<d<<endl;
        return;
    }
    
    for(int i=1;i<=n;i++)
     for(int j=1;j<=i;j++){
        int tmp=a[i]-a[j];
        int id=lower_bound(a+1,a+n+1,tmp)-(a);
        d=min(d,a[id]-tmp);
        if(id>1) d=min(d,tmp-a[id-1]);
     }
     cout<<d<<endl;
}
signed main(){
    
    int n;
    cin>>n;
    cout<<n*sqrt(n)<<endl;
    
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}