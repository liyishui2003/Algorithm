#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5+5;
const int mod = 998244353;
vector<pair<int,int>>e[N];
int n;
int vis[N],dp[N],cnt[N][2];
void dfs(int u){
	if(vis[u]) {
		return;
	}
	vis[u]=1;
	dp[u]=0;
	cnt[u][0]=cnt[u][1]=0;
	for(auto to:e[u]){
		int v=to.first;
		cnt[u][0]+=((to.second)==0);
		cnt[u][0]%=mod;
		cnt[u][1]+=((to.second)==1);
		cnt[u][1]%=mod;
		dp[u]+=(to.second==0)*cnt[u][1]%mod;
		dp[u]%=mod;
		dfs(v);
		if(u==1){
	//		cout<<"add: "<<v<<" "<<dp[v]<<" "<<cnt[v][0]<<" "<<cnt[u][1]<<"\n";
		}
		dp[u]+=(dp[v]+cnt[v][0]*cnt[u][1]%mod)%mod;
		dp[u]%=mod;
		cnt[u][1]+=cnt[v][1];
		cnt[u][1]%=mod;
		cnt[u][0]+=cnt[v][0];
		cnt[u][0]%=mod;
		
	}
//	cout<<"u= "<<u<<" "<<dp[u]<<" "<<cnt[u][1]<<" "<<cnt[u][0]<<"\n";
}
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++){
		int s;cin>>s;
		for(int j=0;j<s;j++){
			int l,w;cin>>l>>w;
			e[i].push_back({l,w});
		}
	}
//	cout<<"success"<<"\n";
	dfs(1);
	cout<<dp[1]<<"\n";
}
signed main(){
	int t=1;
	//cin>>t;
	while(t--){
		solve();
	}
}
/*
8
3
2 1
3 1
4 1
1
5 1
1
5 1
1
5 1
3
6 0
7 0
8 0
0
0
0
*/
