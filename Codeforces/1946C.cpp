#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
vector<int>e[N];
int n,k,siz[N],cnt,flag=0;
void dfs(int u,int fa,int x){
	siz[u]=1;
	for(auto v:e[u]){
		if(v==fa) continue;
		if(flag) return;
		dfs(v,u,x);
		siz[u]+=siz[v];
	}
	if( (siz[u]>=x&&u!=1)&&(flag==0) ) {
		cnt++;
		//cout<<u<<" : "<<cnt<<" "<<siz[u]<<endl;
		siz[u]=0;
	}
	if(cnt==k) flag=1;
}
int check(int x){
	cnt=flag=0;
//	cout<<"==="<<endl;
	dfs(1,0,x);
//	cout<<x<<" ?"<<( (cnt>=k ? 1:0)&&(siz[1]>=x) )<<endl;
	return ( flag )&&(siz[1]>=x);
}
void solve(){
	cin>>n>>k;for(int i=1;i<=n;i++) e[i].clear();
	for(int i=1;i<n;i++){
		int u,v;cin>>u>>v;e[u].push_back(v);e[v].push_back(u);
	}
	int l=1,r=n-1,ans=-1;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid)){
			l=mid+1;ans=mid;
		}
		else r=mid-1;
	}
	cout<<ans<<endl;
}
int main(){
	int t;cin>>t;while(t--){
		solve();
	}
}
