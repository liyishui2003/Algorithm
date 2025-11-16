#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mx2(ll x){
	for(int i=62;i>=0;i--){
		if(x>=(1ll<<i)) {
			return (1ll<<i);
		}
	}
}
void solve(){
	ll l,r;cin>>l>>r;
	ll up=log2(l);
	ll ansl=l;
	for(int i=1;i<=up;i++){
		ll mod=mx2(l);
		if(mod==1) break;
		ll len=r-l;
		l%=mod,r%=mod;
		ll newl=r-l;
		if(l>=r || len!=newl) break;
	//	cout<<l<<" "<<r<<"\n";
		ansl=l;
	}
	cout<<ansl<<"\n";
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--){
		solve();
	}
}
