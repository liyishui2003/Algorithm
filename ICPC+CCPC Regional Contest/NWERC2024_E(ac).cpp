#include<bits/stdc++.h>
using namespace std;
#define int long long 
string s;
int qpow(int a,int b,int mod){
	int ret=1;
	while(b){
		if(b&1) ret=ret*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ret;
}
void solve(){
	int n,k;
	cin>>n>>k;
	cin>>s;
	int base=qpow(2,k,n);
	for(int i=0;i<n;i++){
		int at=i*base%n;
		cout<<s[at];
	}
}
signed main(){
	int t=1;
	while(t--){
		solve();
	}
}
