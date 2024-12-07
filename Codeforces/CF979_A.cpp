#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
	int n;
	cin>>n;
	string s;cin>>s;
	if(s[0]=='1'||s[n-1]=='1'){
		cout<<"YES"<<'\n';
	}
	else {
		for(int i=0;i<n-1;i++){
			if(s[i]=='1'&&s[i+1]=='1'){
				cout<<"YES"<<'\n';
				return;
			}
		}
		cout<<"NO"<<'\n';
	}
}
signed main(){
	int t;cin>>t;
	while(t--){
		//TODO
		solve();
	}
}
