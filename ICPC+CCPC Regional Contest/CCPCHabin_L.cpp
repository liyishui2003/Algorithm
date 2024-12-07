#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5+5;
const int mod = 998244353;
vector<int>e[N];
int n,siz[N],sum[N];

int ans1=0,ans2=0;
void dfs(int u,int f){
	int tot=0;
	siz[u]=1;
	for(auto v:e[u]){
		if(v==f) continue;
		dfs(v,u);
		sum[u]+=sum[v];
		sum[u]%=mod;
		siz[u]+=siz[v];
		siz[u]%=mod;
		ans1+=(siz[v]*siz[v]%mod)*((n-siz[v]+mod)*(n-siz[v]+mod)%mod)%mod;
		ans1%=mod;
		ans2+=2*(n-siz[v]+mod)%mod*(n-siz[v]+mod)%mod*(sum[v]-siz[v]*siz[v]%mod+mod)%mod;
		ans2%=mod;
		tot+=sum[v]%mod;
		tot%=mod;
	}
	sum[u]+=siz[u]*siz[u]%mod;
	sum[u]%=mod;
	for(auto v:e[u]){
		if(v==f) continue;
		ans2+=sum[v]*(tot-sum[v]+mod)%mod;
		ans2%=mod;
	}
}
int qpow(int a,int b){
	int ret=1;
	while(b){
		if(b&1) ret=ret*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ret;
}
int inv(int x){
	return qpow(x,mod-2);
}
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++) 
	{
		e[i].clear();
		siz[i]=sum[i]=0;
	}
	ans1=ans2=0;
	
	for(int i=1;i<n;i++){
		int u,v;cin>>u>>v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs(1,0);
	int tot=n*(n-1)/2;
	tot%=mod;
	tot=tot*tot%mod;
	
	cout<<(ans1+ans2)%mod*inv(tot)%mod<<'\n';
}
signed main(){
	int t;
	cin>>t;
	while(t--){
		solve();
	}
}
