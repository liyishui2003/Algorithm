#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6+5;
const int mod = 998244353;
int n,b[N],k[N],child[N],f[N];
vector<int>e[N];
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
void dfs(int u,int f){
	int isleaf=1,shor=INT_MAX,pos=-1;
	for(auto v:e[u]){
		if(v==f) continue;
		dfs(v,u);
		if(child[v]+1<shor){
			shor=child[v]+1;
			pos=v;
		}
		isleaf=0;
	}
	child[u]=shor;
	if(isleaf){
		b[u]=k[u]=0;
		child[u]=0;
	}
	else {
		b[u]=0;
		k[u]=inv(2-k[pos]+mod)%mod;
	}
}
void dfs2(int u,int pa){
	
	if(u!=1) f[u]=k[u]*f[pa]%mod;
	else f[u]=1;
	for(auto v:e[u]){
		if(v==pa) continue;
		dfs2(v,u);
	}
}
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++) e[i].clear();
	for(int i=1;i<n;i++){
		int u,v;cin>>u>>v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs(1,0);
	dfs2(1,0);
	for(int i=1;i<=n;i++){
		cout<<f[i]<<" ";
	}
	cout<<'\n';
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
