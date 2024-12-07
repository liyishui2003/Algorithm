#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6+5;
int a[N],vis[N],f[N],d[N];
map<int,int>mp,valid;
int dfs(int i){
	if(vis[i]) return f[i];
	vis[i]=1;
	int ans=i-1;
	if(valid[d[i]+i-1]){
	//	cout<<i<<" to "<<mp[d[i]+i-1]+1<<'\n';
		f[i]=ans+dfs(mp[d[i]+i-1]+1);
		return f[i];
	}
	else return f[i]=ans;
}
void solve(){
	int n;cin>>n;
	for(int i=1;i<=n;i++) vis[i]=f[i]=d[i]=0;
	mp.clear();
	valid.clear();
	for(int i=1;i<=n;i++){
		cin>>a[i];
		d[i]=a[i]+i;
	    mp[d[i]]=max(mp[d[i]],i-1);
		valid[d[i]]=1;
	}
	
	int out=0;
	for(int i=1;i<=n;i++){
		int ans=0;
		if(a[i]==n+1-i){
			ans=dfs(i);
		}
		out=max(out,ans);
	}
	cout<<out+n<<'\n';
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
