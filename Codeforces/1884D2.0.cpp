#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+5;int a[N];
void solve(){
	int n;cin>>n;
	vector<int>cnt(n+5),g(n+5);
	for(int i=1;i<=n;i++) cin>>a[i],cnt[a[i]]++;
	for(int i=n;i>=1;i--){
		int sum=0;
		for(int j=i;j<=n;j+=i) sum+=cnt[j];
		g[i]=sum*(sum-1)/2;
		for(int j=i*2;j<=n;j+=i) g[i]-=g[j];
	}
	for(int i=1;i<=n;i++){
		if(cnt[i])
			for(int j=i;j<=n;j+=i) g[j]=0;
	}
	int ans=0;for(int i=1;i<=n;i++) ans+=g[i];
	cout<<ans<<"\n";
}
signed main(){
	int t;cin>>t;while(t--) solve();
}
