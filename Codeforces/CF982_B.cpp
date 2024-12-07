#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[5000];
void solve(){
	
	int n;cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int out = n;
	for(int i=1;i<=n;i++){
		
		int ans=i-1;
		for(int j=i+1;j<=n;j++){
			if(a[j]>a[i]) ans++;
		}
	//	cout<<i<<" "<<ans<<'\n';
		out=min(out,ans);
	}
	cout<<out<<'\n';
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
