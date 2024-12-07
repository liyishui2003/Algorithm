#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 3e5+5;
const int mod = 1e9+7;
int a[N],b[N],sum[N],suf[N],sufsum[N];
int n,m;
int qpow(int a,int b){
	int ret=1;
	while(b){
		//TODO
		if(b&1) ret=ret*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ret;
}
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
int query2(int i,int x){
	int l=i,r=n,ans=-1;
	if(sum[n]-sum[i-1]<=x) return n;
	while(l<=r){
		int mid=(l+r)>>1;
		if(sum[mid]-sum[i-1]<=x){
			ans=mid;
			l=mid+1;
		}
		else r=mid-1;
	}
	return ans;
}
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		sum[i]=sum[i-1]+a[i];
	}
	for(int i=1;i<=m;i++) cin>>b[i];
	
	int dp[n+5][m+5],g[n+5][m+5];
	int f[n+5][m+5],F[n+5][m+5];
	for(int i=0;i<=n;i++)
		for(int j=0;j<=m;j++){
			dp[i][j]=g[i][j]=1e16;
			f[i][j]=F[i][j]=0;
		}
	
	for(int j=0;j<=m;j++) {
		dp[0][j]=g[0][j]=0;
		f[0][j]=F[0][j]=1;
	}
		
	for(int i=0;i<=n+2;i++) suf[i]=sufsum[i]=0;
	suf[n+1]=1;
	sufsum[n+1]=1;
	for(int i=n;i>=1;i--){
		if(a[i]>b[m]) break;
		int _i=query2(i,b[m]);
		suf[i]=(sufsum[i+1]-sufsum[_i+2]+mod)%mod;
		sufsum[i]=(sufsum[i+1]+suf[i])%mod;
		cout<<i<<" suf: "<<suf[i]<<'\n';
	}
	int mi=1e16;
	for(int i=1;i<=n;i++){	
		for(int j=1;j<=m;j++){
			int _i=query(i,b[j]);
			if(_i==-1) continue;
			dp[i][j]=min(dp[i][j],g[_i][j]+(m-j));
			if(i==n) mi=min(mi,dp[i][j]);
			
			if(dp[i][j]==g[_i][j]+(m-j)&&j!=m){
				f[i][j]=F[_i][j];
				cout<<"["<<i<<","<<j<<"] "<<f[i][j]<<" "<<dp[i][j]<<'\n';
			}
			else f[i][j]=0;
		}
		// f[i][j] 使dp[i][j]取到最小值的方案数
		// (包括了dp[i][1],dp[i][2],...dp[i][j])
		// g[i][j] 是dp[i][1],dp[i][2],...dp[i][j]的最小值
		// F[i][j] 使dp[i][1],dp[i][2],...dp[i][j]取到最小值时不同来源的总方案数
		// 更新时：f[i][j]=F[_i][j]
		// F[i][j] = 
		for(int j=1;j<=m-1;j++){
			if(dp[i][j]<g[i][j-1]){
				g[i][j]=dp[i][j];
				F[i][j]=f[i][j];
			}
			else if(dp[i][j]==g[i][j-1]){
				g[i][j]=g[i][j-1];
				F[i][j]=F[i][j-1]+f[i][j];
				F[i][j]%=mod;
			}
			else if(dp[i][j]>g[i][j-1]){
				g[i][j]=g[i][j-1];
				F[i][j]=F[i][j-1];
			}
		}
	}
	int tot=0;
	
	for(int i=n;i>=1;i--)
		for(int j=1;j<=m;j++){
			if(suf[i+1]) mi=min(mi,dp[i][j]);
	}
	cout<<"mi= "<<mi<<'\n';
	cout<<"F[n][m-1] "<<F[n][m-1]<<'\n';
	
	for(int i=n;i>=1;i--){
		if(suf[i+1]==0) break;
		for(int j=1;j<=m-1;j++){
			if(dp[i][j]==mi){
				tot=tot+suf[i+1]*f[i][j]%mod,tot%=mod;
				cout<<"i j "<<i<<" "<<j<<" "<<suf[i+1]<<" "<<f[i][j]<<'\n';
			}
		}
	}
	for(int j=1;j<=m-1;j++) {
		if(dp[n][j]==mi) tot=(tot+f[n][j])%mod;
	}
	if(mi==1e16) cout<<-1<<'\n';
	else cout<<mi<<' ',cout<<tot<<'\n';
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
