#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 3e5+5;
int a[N],b[N],sum[N];
int query(int i,int x){
	int l=1,r=i,ans=-1;
	if(sum[i]<=x) return 0;// special judge
	while(l<=r){
		int mid=(l+r)>>1;
		if(sum[i]-sum[mid]<=x){
			ans=mid;
			r=mid-1;
		}
		else l=mid+1;
	}
	return ans;
}
void solve(){
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		sum[i]=sum[i-1]+a[i];
	}
	for(int i=1;i<=m;i++) cin>>b[i];
	
	int dp[n+5][m+5],g[n+5][m+5];
	for(int i=0;i<=n;i++)
		for(int j=0;j<=m;j++){
			dp[i][j]=g[i][j]=1e16;
	}
	
	for(int j=0;j<=m;j++) 
		dp[0][j]=g[0][j]=0;
	
	for(int i=1;i<=n;i++){	
		for(int j=1;j<=m;j++){
			int _i=query(i,b[j]);
			if(_i==-1) continue;
			dp[i][j]=min(dp[i][j],g[_i][j]+(m-j));
		//	cout<<"["<<i<<","<<j<<"] "<<dp[i][j]<<" "<<_i<<'\n';
		}
		for(int j=1;j<=m;j++){
			g[i][j]=min(g[i][j-1],dp[i][j]);
		}
	}
	if(g[n][m]==1e16) cout<<-1<<'\n';
	else cout<<g[n][m]<<'\n';
}
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--){
		//TODO
		solve();
	}
}
