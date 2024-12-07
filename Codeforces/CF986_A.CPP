#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
	int n,b,c;cin>>n>>b>>c;
	int d=n-1;
	//[0,d] 有多少个等差数列中的数
	if(n==1){
		if(c==0) cout<<"0"<<'\n';
		else cout<<"1"<<'\n';
		return;
	}
	if(b==0){
		if(n<=c+2){
			if(c<=d) cout<<n-1<<'\n';
			else cout<<n<<'\n';
		}
		else cout<<"-1"<<'\n';
	}
	else {// b>0
		if(c>d){
			cout<<n<<'\n';
			return;
		}
		else {
			// c<=d
			int lef=d-c;
			lef/=b;
			cout<<n-lef-1<<'\n';
		}	
	}
}
signed main(){
	//ios_base::sync_with_stdio(false);
	//cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--){
		//TODO
		solve();
	}
}
