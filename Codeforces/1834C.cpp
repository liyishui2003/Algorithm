#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    string s,t;
    cin>>s>>t;
    int cnt1=0,cnt2=0;
    for(int i=0;i<n;i++){
        cnt1+=(s[i]!=t[i]);
        cnt2+=(s[i]!=t[n-i-1]);
    }
    int ans1,ans2;
    if(cnt1==0){
        ans1=0;
    }
    else {
        if(cnt1%2==1) ans1=cnt1*2-1;
        else ans1=cnt1*2;
    }

    if(cnt2==0){
        ans2=2;
    }
    else {
        if(cnt2%2==1) ans2=cnt2*2;
        else ans2=cnt2*2-1;
    }
    cout<<min(ans1,ans2)<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}