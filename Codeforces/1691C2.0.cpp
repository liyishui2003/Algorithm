#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n,k;
    cin>>n>>k;
    string s;cin>>s;
    int cnt1=0,cnt2=0,sum=0;
    for(int i=0;i<n;i++){
        if(s[i]=='1') break;
        cnt1++;
    }
    for(int i=n-1;i>=0;i--){
        if(s[i]=='1') break;
        cnt2++;
    }
    for(int i=0;i<n-1;i++){
        int a1=s[i]-'0',a2=s[i+1]-'0';
        sum+=a1*10+a2;
    }
    if(cnt1+cnt2==2*n)   cout<<0<<endl; // no 1
    else if(cnt1+cnt2==n-1){// only 1 
        if(cnt2<=k&&cnt2) cout<<sum-10<<endl;
        else if(cnt1<=k&&cnt1&&cnt2) cout<<sum-1<<endl;
        else cout<<sum<<endl;
    }
    else {
        if(cnt2<=k&&cnt2) {
            k-=cnt2;sum-=10;
        }
        if(cnt1<=k&&cnt1) {
            k-=cnt1;sum-=1;
        }
        cout<<sum<<endl;
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}