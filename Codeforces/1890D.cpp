#include<bits/stdc++.h>
using namespace std;
using ll =long long;
const int N=1e6+5;
void solve(){
	ll n,c;cin>>n>>c;
	vector<ll>a(n+5);for(int i=1;i<=n;i++) cin>>a[i];
	pair<ll,int>b[n+5];
	for(int i=2;i<=n;i++) {
		b[i]={i*c-a[i],i};
	}
	sort(b+2,b+n+1);
	ll s=a[1],flag=1;
	for(int i=2;i<=n;i++){
		if(s>=b[i].first) {
			s+=a[b[i].second];
		}
		else flag=0;
	}
	if(flag) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
}
int main(){
	//freopen("lys.in","r",stdin);
	int t;cin>>t;while(t--)solve();
}
