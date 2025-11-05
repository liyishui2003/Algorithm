#include<bits/stdc++.h>
using namespace std;
const int maxn = 2*100005;
int n,m,k,vis[maxn],a[maxn],b[maxn],zihuan[maxn];
void solve(){
	cin>>n>>m>>k;
	
	for(int i=1;i<=k;i++) vis[i]=0,zihuan[i]=0;
	
	for(int i=1;i<=n;i++){
		int f;cin>>f;
		vis[f]=1;
	}
	int ans=0;
	map<pair<int,int>,int>mp;
	for(int i=1;i<=m;i++){
		cin>>a[i]>>b[i];
		if(a[i]==b[i]){
			if(vis[a[i]]) ans++;
			else zihuan[a[i]]++;
		}
		else {
			if(vis[a[i]] && vis[b[i]]){
				//两个人都是我好友
				ans++;
			}
			else if(vis[a[i]] && !vis[b[i]]){
				//a是,b不是
				zihuan[b[i]]++;
			}
			else if(!vis[a[i]] && vis[b[i]]){
				zihuan[a[i]]++;
			}
			else if(!vis[a[i]] && !vis[b[i]]){
				//这两个人都不是我好友
				int u=a[i],v=b[i];
				if(u>v) swap(u,v);
				//两人之间的连边增加，不计算zihuan贡献
				mp[make_pair(u,v)]++;
			}
		}
	}
	//1.特判朋友只能新增0/1个的情况
	if(k<=n+1){
		for(int i=1;i<=m;i++){
			if(vis[a[i]] && vis[b[i]]){
				//两个人都是我好友
				continue;
			}
			ans++;
		}
		cout<<ans<<"\n";
		return;
	}
	
	//2.现在加2个好友
	//2.1 都是自环
	int add=0;
	vector<int>zh;
	for(int i=1;i<=k;i++){
		if(vis[i]) continue;
		zh.push_back(zihuan[i]);
	}
	int sz=zh.size();
	sort(zh.begin(),zh.end());
	add=max(add,zh[sz-2]+zh[sz-1]);

	//2.2 link(a,b)
	for(int i=1;i<=m;i++){
		if(a[i]==b[i]) continue;
		if(!vis[a[i]] && !vis[b[i]]){
			int u=a[i],v=b[i];
			if(u>v) swap(u,v);
			//两人之间的连边增加，不计算zihuan贡献
			int tmp=mp[make_pair(u,v)];
			tmp+=zihuan[a[i]]+zihuan[b[i]];
			add=max(add,tmp);
		}
	}
	cout<<ans+add<<"\n";
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		//TODO
		solve();
	}
}
/*
2
1 5 5
5
1 1
2 5
3 5
4 5
2 2
1 6 5
5
1 3
2 3
1 4
4 5
2 5
5 4
*/
