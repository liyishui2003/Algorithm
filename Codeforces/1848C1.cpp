#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int a[N],b[N];
void solve(){
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        cin>>b[i];
    }
    int ans[3]={0},cnt=0,flag=0;
    for(int i=1;i<=n;i++){
        if(a[i]==0&&b[i]==0) continue;
        if(!a[i]){
            flag=1;
        }
        if(!a[i]) continue;
        cnt++;
        if(a[i]&&b[i]){
            int g=__gcd(a[i],b[i]);
            a[i]/=g,b[i]/=g;
        }
        if(a[i]%2==1&&b[i]%2==1){
            ans[0]++;
        }
        else if(a[i]%2==0&&b[i]%2==1){
            ans[1]++;
        }
        else ans[2]++;
    }
    n=cnt;
    if(flag){
        if(ans[1]==n ) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        return;
    }
    if(ans[0]==n ||ans[1]==n || ans[2]==n )cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}