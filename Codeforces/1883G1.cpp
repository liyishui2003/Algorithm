#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
#define int long long
int a[N],b[N],vis[N];
void solve(){
	int n;cin>>n;for(int i=1;i<=n;i++) cin>>a[i],b[i]=0,vis[i]=0;
	for(int i=1;i<=n;i++)	b[a[i]]++;
	int ans=0;
	for(int i=1;i<=n;i++){
		if(!b[i]||vis[i]) continue;
		int sum=0;
		for(int j=2;j*i<=n;j++) sum+=b[j*i],vis[j*i]=1;
		// c(sum,2)
		ans+=sum*(sum-1)/2;
		ans+=sum*b[i];
		ans+=b[i]*(b[i]-1)/2;
		//cout<<i<<" "<<sum<<" "<<b[i]<<endl;
	}
	int tot=n*(n-1)/2;
	//cout<<ans<<endl;
	cout<<tot-ans<<endl;
}
signed main(){
	int t;cin>>t;while(t--) solve();
}
