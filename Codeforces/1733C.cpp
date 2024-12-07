#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int a[N];
void solve(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];

    vector<pair<int,int>>ans;
    
    if(a[1]!=a[n]) {
        ans.push_back({1,n});
        if((a[1]+a[n])%2==1) a[n]=a[1];
        else a[1]=a[n];
    }

    for(int i=2;i<n;i++){
        if((a[i]+a[1])%2==1){
            ans.push_back({1,i});
        }
        else ans.push_back({i,n});
    }

    cout<<ans.size()<<endl;
    for(auto v:ans){
        cout<<v.first<<" "<<v.second<<endl;
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}