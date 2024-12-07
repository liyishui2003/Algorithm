#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int a[N];
void solve(){
    int n;
    cin>>n;
    map<int,int>mp;
    for(int i=1;i<=n;i++) cin>>a[i],mp[a[i]]=1;
    int mex=0;
    for(int i=0;i<=n;i++){
        if(!mp[i]) {
            mex=i;break;
        }
    }
    vector<pair<int,int>>ans;
    mp.clear();
    int cnt=0,lastl=1;
    for(int i=1;i<=n;i++){
        if(a[i]<mex){
            if(!mp[a[i]]) {
                mp[a[i]]=1;
                cnt++;
            }
        }
        if(cnt==mex){
           // cout<<lastl<<" "<<i<<endl;
            ans.push_back({lastl,i});
            lastl=i+1;
            cnt=0;
            mp.clear();
        }
    }
    if(ans.size()<2) {
        cout<<-1<<endl;return;
    }
    int id=ans.size();
    cout<<id<<endl;
    for(int i=0;i<=id-2;i++) cout<<ans[i].first<<" "<<ans[i].second<<endl;
    if(ans[id-1].second!=n){
        cout<<ans[id-1].first<<" "<<n<<endl;
    }
    else cout<<ans[id-1].first<<" "<<ans[id-1].second<<endl;
}
int main(){

    cout<<2000*2000*log2(2000)<<endl;
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}