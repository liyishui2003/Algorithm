#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[105],dp[105];
const int inf=998244353;
void solve(){
    int n;
    cin>>n;
    if(n<=100){
        cout<<dp[n]<<endl;
        return;
    }
    else {
        n-=100;
        int tot=(n/15)*15;
        int lf=n-tot+100;
        //cout<<"lf "<<lf<<endl;
        cout<<(n/15)+dp[lf]<<endl;
    }
}
void init(){
    dp[0]=0;
    int a[6];
    a[1]=1;a[2]=3;a[3]=6;a[4]=10;a[5]=15;
    for(int i=1;i<=150;i++){
        dp[i]=inf;
        for(int j=1;j<=5;j++)
          if(a[j]<=i) dp[i]=min(dp[i],dp[i-a[j]]+1);
    }
}
signed main(){
    init();
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}