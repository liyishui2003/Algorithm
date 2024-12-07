#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int mod=998244353;
bool cmp(int a,int b) {return a<b;}
int pow(int a,int b){
	int ans=1;while(b){if(b&1) ans=ans*a%mod;a=a*a%mod;b>>=1;}return ans;
}
void solve(){
	int n;cin>>n;
	int a[n+5];for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		int mx=a[i];
		for(int j=i;j<=n;j+=i) mx=max(mx,a[j]);
		a[i]=mx;
	}
	sort(a+1,a+n+1,cmp);
	int sum=0;
	for(int i=1;i<=n;i++){
		sum+=pow(1ll*2,i-1)*a[i]%mod;sum%=mod;
	}
	cout<<sum<<endl;
}
signed main(){
	int t;t=1;while(t--) solve();
}
