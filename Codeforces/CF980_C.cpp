#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+5;
struct node{
	int a,b;
	int val;
}f[N];
bool cmp(node a,node b){
	return a.val<b.val;
}
void solve(){
	int n;cin>>n;
	for(int i=1;i<=n;i++){
		int u,v;cin>>u>>v;
		f[i].a=u,f[i].b=v,f[i].val=u+v;
	}
	sort(f+1,f+n+1,cmp);
	for(int i=1;i<=n;i++){
		cout<<f[i].a<<" "<<f[i].b<<" ";
	}
	cout<<'\n';
}
signed main(){
	int t;cin>>t;
	while(t--){
		//TODO
		solve();
	}
}
