#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+5;
int n;
int a[N],suf[N],sum[N];
void solve(){
	cin>>n;
	map<int,int>mp;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(a[1]+a[2]>a[n]){
		cout<<0<<'\n';
		return;
	}
	int ans=n;
	for(int i=1;i<=n-2;i++){
		int mx=a[i]+a[i+1];
		if(a[i]+a[i+1]>a[n]){
			ans=min(ans,i-1);
		}
		else {
			int to=lower_bound(a+1,a+n+1,mx)-a;
			ans=min(ans,i-1+(n-to+1));	
		}
	}
	cout<<ans<<'\n';
}
signed main(){
	int t;
	cin>>t;
	while(t--){
		//TODO
		solve();
	}
}
