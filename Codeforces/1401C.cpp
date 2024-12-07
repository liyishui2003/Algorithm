#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int a[N],b[N];
void solve(){
    int n;cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i],b[i]=a[i];
    int mi=INT_MAX;
    for(int i=1;i<=n;i++) mi=min(mi,a[i]);
    int flag=1;
    for(int i=2;i<=n;i++){
        if(a[i]<a[i-1]) flag=0;
    }
    if(flag) {
        cout<<"YES"<<endl;
        return;
    }
    flag=1;
    sort(b+1,b+n+1);
    for(int i=1;i<=n;i++){
        if(a[i]%mi&&b[i]!=a[i]) flag=0;
    }
    if(flag) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}