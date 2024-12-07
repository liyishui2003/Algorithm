#include<bits/stdc++.h>
using namespace std;
int k;
int ask(int l,int r){ if(l==r) return 0;cout<<"? "<<l<<" "<<r<<endl;fflush(stdout);cin>>k;return k; }
int deal(int l,int r){
	if(l==r) return l;
	int mid=(l+r)>>1;
	int p=deal(l,mid),q=deal(mid+1,r);
	return (ask(p,q-1)==ask(p,q)) ? q:p;
}
void solve(){
	int n;cin>>n;int ans=deal(1,n);
	cout<<"! "<<ans<<endl;fflush(stdout);
}
int main(){
	cout<<((1e5)*(1e5)/64)<<endl;
	int t;cin>>t;while(t--) solve();
}
