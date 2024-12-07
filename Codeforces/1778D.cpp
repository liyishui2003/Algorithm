#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+5;
const int mod=998244353;
int n,ans[N];
int qpow(int a,int b){
	int ret=1;while(b){
		if(b&1) ret=ret*a%mod;
		a=a*a%mod;b>>=1;
	}
}
int inv(int x){
	return qpow(x,mod-2);
}
int dfs(int x){
	if(x==n-1){
		return ans[x]=(n*n%mod-1+mod)%mod;
	}
	ans[x]=(x+x*inv(x+1)%mod*dfs(x+1)%mod)%mod;
}
void solve(){
	cin>>n;string a,b;cin>>a>>b;
	a=" "+a;b=" "+b;
	int cnt=0;
	for(int i=1;i<=n;i++){
		cnt+=(a[i]!=b[i]);
	}
	if(cnt==0){
		cout<<0<<endl;return;
	}
	if(n==1){
		cout<<1<<endl;return;
	}
	dfs(1);
	cout<<ans[cnt]<<endl;
}
signed main(){
	int t;cin>>t;while(t--) solve();
}
