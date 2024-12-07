#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6+5;
int a[N],to[N];
void solve(){
	int n;cin>>n;
	if(n%2==1){
		cout<<-1<<'\n';
		return;
	}
	else {
		for(int i=1;i<=n;i+=2){
			cout<<i<<" "<<i<<" ";
		}
		cout<<'\n';
	}
}
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--){
		//TODO
		solve();
	}
}
