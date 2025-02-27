#include<bits/stdc++.h>
using namespace std;
const int N = 3e5+5;
typedef long long ll;
const int mod = 998244353;
int n;
vector<int>e[N];
ll ans[N],dTot[N];
struct node{
	int d,u,pa;
}f[N];
void dfs(int u,int pa,int d){
	f[u]=(node){d,u,pa};
	for(auto v:e[u]){
		if(v==pa) continue;
		dfs(v,u,d+1);
	}
}
bool cmp(node a,node b){
	return a.d > b.d;
}
void solve(){
	cin>>n;
	for(int i=0;i<=n+5;i++){
		ans[i]=dTot[i]=0;
		e[i].clear();
	}
	for(int i=2;i<=n;i++){
		int p;cin>>p;
		e[p].push_back(i);
	}
	dfs(1,0,0);
	sort(f+1,f+n+1,cmp);
	
	for(int i=1;i<n;i++){
		int d=f[i].d,u=f[i].u;
		ll tot = dTot[d+1];
		for(auto v:e[u]){
			if(v==f[i].pa) continue;
			tot = (tot - ans[v] +mod)%mod;
		}
		tot = (tot+1)%mod;
		ans[u] = tot;
		dTot[d] = (dTot[d] + tot)%mod;
	//	cout<<"u= "<<u<<" ans[u]= "<<ans[u]<<endl;
	}
	ans[1]=1;
	for(auto v:e[1]){
		ans[1]=(ans[1]+ans[v])%mod;
	}
	cout<<ans[1]<<endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	int t;
	cin>>t;
	while(t--){
		solve();
	}
}
