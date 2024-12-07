#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int a[N];
void solve(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

    int l=1,r=n;
    for(int i=1;i<=(n+1)/2;i++){
        if(a[i]==i||a[i]==n-i+1) {}
        else {
            l=i;break;
        }
    }

    for(int i=n;i>=(n+1)/2;i--){
        if(a[i]==i||a[i]==n-i+1) {}
        else {
            r=i;break;
        }
    }

    
    if(l>r||abs(r-l+1)<=2) {
        cout<<-1<<endl;
        return ;
    }
    int mx=-1,mi=INT_MAX;
    for(int i=l;i<=r;i++){
        mx=max(mx,a[i]);
        mi=min(mi,a[i]);
    }
    if(a[l]==mx||a[l]==mi||a[r]==mx||a[r]==mi) cout<<-1<<endl;
    else cout<<l<<" "<<r<<endl; 
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}