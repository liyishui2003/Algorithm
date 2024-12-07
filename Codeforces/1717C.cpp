#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
int a[N],b[N];
void solve(){
	int n;cin>>n;
	for(int i=1;i<=n;++i) cin>>a[i];
	for(int i=1;i<=n;++i) cin>>b[i];
	b[n+1] = b[1];
	for(int i=1;i<=n;++i){
		if(a[i]>b[i]||(b[i]>b[i+1]+1 && a[i]!=b[i])){
			cout<<"NO\n";
			return;
		}
	}
	cout<<"YES\n";
}
signed main(){
	int T;cin>>T;
	while(T--) solve();
	return 0;
}