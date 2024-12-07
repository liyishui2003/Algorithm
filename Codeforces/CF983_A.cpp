#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
	int n;cin>>n;
	int cnt0=0,cnt1=0;
	for(int i=1;i<=n*2;i++){
		int u;cin>>u;
		cnt0+=(u==0);
		cnt1+=(u==1);
	}
	if(cnt0%2==0) cout<<0<<" ";
	else cout<<1<<" ";
	cout<<min(cnt0,cnt1)<<'\n';
}
signed main(){
	int t;
	cin>>t;
	while(t--){
		//TODO
		solve();
	}
}
