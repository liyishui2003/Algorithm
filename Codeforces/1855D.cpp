#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
// 这份代码默认节点编号从 1 开始，即 i ∈ [1,n]
int siz[N],  // 这个节点的「大小」（所有子树上节点数 + 该节点）
weight[N],  // 这个节点的「重量」，即所有子树「大小」的最大值
centroid[2];  // 用于记录树的重心（存的是节点编号）
vector<int>e[N];
int n;
void GetCentroid(int cur, int fa) {  // cur 表示当前节点 (current)
	siz[cur] = 1;
	weight[cur] = 0;
	for (auto to:e[cur]) {
		if (to != fa) {  // e[i].to 表示这条有向边所通向的节点。
			GetCentroid(to, cur);
			siz[cur] += siz[to];
			weight[cur] = max(weight[cur], siz[to]);
		}
	}
	weight[cur] = max(weight[cur], n - siz[cur]);
	if (weight[cur] <= n / 2) {  // 依照树的重心的定义统计
		centroid[centroid[0] != 0] = cur;
	}
}
int dep[N],mx[N][2];
void dfs(int rt,int fa){
	dep[rt]=dep[fa]+1;
	mx[rt][0]=mx[rt][1]=0;
	for(auto v:e[rt]){
		if(v==fa) continue;
		dfs(v,rt);
		if(mx[v][0]>=mx[rt][0]){
			mx[rt][1]=mx[rt][0];mx[rt][0]=mx[v][0];
		}
		else if(mx[v][0]>mx[rt][1]&&mx[v][0]<mx[rt][0]){
			mx[rt][1]=mx[v][0];
		}
	}
	if(e[rt].size()==1) mx[rt][0]=dep[rt];
}
queue<pair<int,int>>q;
int f[N],ans[N],vis[N];
void dfs2(int rt,int fa,int need){
	if(dep[rt]==need) q.push({rt,1}),vis[rt]=1;
	f[rt]=fa;
	for(auto v:e[rt]){
		if(v==fa) continue;
		dfs2(v,rt,need);
	}
}
void solve(){
	cin>>n;
	if(n==2){
		
		return;
	}
	for(int i=1;i<=n;i++) e[i].clear(),siz[i]=weight[i]=0;
	centroid[0]=centroid[1]=0;
	for(int i=1;i<n;i++){
		int x,y;cin>>x>>y;
		e[x].push_back(y);
		e[y].push_back(x);
	}
	GetCentroid(1,0);
	int rt=centroid[0];
	dfs(rt,0);
	int d=mx[rt][0]+mx[rt][1]-2,p=1;
	cout<<"rt "<<rt<<" "<<mx[rt][0]<<" "<<mx[rt][1]<<endl;
	dfs2(rt,0,mx[rt][0]);
	int from=-1;
	for(auto v:e[rt]){
		if(mx[rt][0]==mx[v][0]) from=v;
	}
	if(mx[rt][0]!=mx[rt][1]){
		for(auto v:e[rt]){
			if(v==from) continue;
			dfs2(v,rt,mx[rt][1]);
		}
	}
	for(int i=d;i<=n;i++) ans[i]=n;
	while(!q.empty()){
		auto x=q.front();q.pop();
		if(x.second==p){
			cout<<x.first<<" "<<d-p+1<<endl;
			ans[d-p+1]--;
			if(!vis[f[x.first]]){
				q.push({f[x.first],x.second+1});
				vis[f[x.first]]=1;
			}
		}
		else {
			if(p==1) ans[d]++;
			p++;
			ans[d-p+1]=ans[d-(p-1)+1];
			ans[d-p+1]--;
			cout<<x.first<<" ::  "<<d-p+1<<endl;
			if(!vis[f[x.first]]){
				q.push({f[x.first],x.second+1});
				vis[f[x.first]]=1;
			}
		}
	}
	for(int i=1;i<=n;i++) cout<<max(1,ans[i])<<" ";
}
int main(){
	int t=1;
	//cin>>t;
	while(t--){
		solve();
	}
}

