#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N = 3e5+5;
int a[N];
void solve(){
	int n;cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	
	set<pair<int,int>>s;
	for(int i=1;i<=n;i++) {
		s.insert({a[i]+i-1,a[i]+2*(i-1)});
	}
	map<int,int>vis;
	vis[n]=1;
	int ans=n;
	while(!s.empty()){
		auto it=*s.begin();
		if(vis[it.first]) {
			vis[it.second]=1;
			ans=max(ans,it.second);
		}
		s.erase(it);
	}
	cout<<ans<<'\n';
}
signed main(){
	int t;cin>>t;
	while(t--){
		//TODO
		solve();
	}
}
