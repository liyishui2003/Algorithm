#include<bits/stdc++.h>
using namespace std;
const int N=2e3+5;
#define int long long
struct node{
    int a,b;
}f[N];
int dp[N][N],s[N];
bool cmp(node x,node y){
    if(x.b==y.b) return x.a<y.a;
    else return x.b<y.b;
}
void solve(){
    int n,l;cin>>n>>l;
    for(int i=1;i<=n;i++)  cin>>f[i].a>>f[i].b;
    sort(f+1,f+n+1,cmp);

    int ans=-1;
    for(int i=1;i<=n;i++)
     for(int j=1;j<=n;j++)
        dp[i][j]=1e15,s[j]=1e15;
        
    for(int i=1;i<=n;i++){

        dp[i][1]=f[i].a;
        for(int j=i;j>=2;j--){
            dp[i][j]=min(dp[i][j],s[j-1]+f[i].a+f[i].b);
            s[j]=min(s[j],dp[i][j]-f[i].b);
            /*
            for(int k=1;k<i;k++)
            if(j-1<=k) {
                dp[i][j]=min(dp[k][j-1]+f[i].a+f[i].b-f[k].b,dp[i][j]);
            }
            */
           //cout<<i<<" "<<j<<" # "<<dp[i][j]<<" "<<s[j-1]<<" "<<endl;
        }
        s[1]=min(s[1],dp[i][1]-f[i].b);
    }
     
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
          //  cout<<i<<" "<<j<<" # "<<dp[i][j]<<endl;
            if(dp[i][j]<=l) ans=max(ans,j);
        }
    cout<<max(ans,1ll*0)<<endl;
}
signed main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}