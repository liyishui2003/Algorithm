#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
	int n,k;
	cin>>n>>k;
	if(n==1) {
		cout<<1<<'\n'<<1<<'\n';
		return;
	}
	if(k==1||k==n) {
		cout<<-1<<'\n';
		return;
	}
	vector<int>a;
	if(k%2==0){
		a.push_back(1);
		a.push_back(k);
		a.push_back(k+1);
	}
	else {
		a.push_back(1);
		a.push_back(k-1);
		a.push_back(k+2);
	}
	
	cout<<a.size()<<'\n';
	for(auto v:a){
		cout<<v<<" ";
	}
	cout<<'\n';
}
signed main(){
	int t;
	cin>>t;
	while(t--){
		//TODO
		solve();
	}
}
