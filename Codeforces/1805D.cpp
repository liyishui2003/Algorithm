#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n;
vector<int>e[N];
int w,c,dep[N],dep_w[N],dep_c[N];
void dfs(int rt,int fa){
	dep[rt]=dep[fa]+1;
	for(auto v:e[rt]){
		if(v==fa) continue;dfs(v,rt);
		if(dep[v]>dep[w]) w=v;
	}
}
void dfs2(int rt,int fa){
	dep_w[rt]=dep_w[fa]+1;
	for(auto v:e[rt]){
		if(v==fa) continue;
		dfs2(v,rt);
		if(dep_w[v]>dep_w[c]) c=v;
	}
}
void dfs3(int rt,int fa){
	dep_c[rt]=dep_c[fa]+1;
	for(auto v:e[rt]){
		if(v==fa) continue;
		dfs3(v,rt);
	}
}
void solve(){
	cin>>n;for(int i=1;i<n;i++) {
		int u,v;cin>>u>>v;e[u].push_back(v);e[v].push_back(u);
	}
	dfs(1,0);
	// w 
	dfs2(w,0);
	// c
	dfs3(c,0);
	vector<int>cnt(n+5);
	//cout<<w<<" "<<c<<endl;
	for(int i=1;i<=n;i++){
	//	cout<<i<<" :: "<<max(dep_c[i],dep_w[i])-1<<endl;
		if(i!=w)cnt[max(dep_c[i],dep_w[i])-1]++;
	}
	int ans=1;
	for(int i=1;i<=n;i++){
		ans+=cnt[i-1];cout<<ans<<" ";
	}
}
int main(){
	int t=1;while(t--)solve();
}
