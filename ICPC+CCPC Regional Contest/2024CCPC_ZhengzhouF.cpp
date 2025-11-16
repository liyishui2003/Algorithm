#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=4e5+10;
ll a[maxn];
ll b[maxn];
ll pre[maxn];
vector<pair<ll,ll>> v(maxn);
void solve(){
	ll n,k,q;
	cin>>n>>k>>q;
	ll x,y;
	ll sumt=0;
	pre[0]=0;
	for(int i=1;i<=n;i++){
		cin>>x>>y;
		a[i]=x-1;
		b[i]=y;
		sumt+=b[i];
		pre[i]=pre[i-1]+b[i];
	}
	v[0]={1,0};
	ll pos;
	for(int i=1;i<=3*n;i++){
		auto [d,h]=v[i-1];
		ll d1,h1;
		pos=i%n;
		if(pos==0)pos=n;
		if(d<(i-1)/n+1||(d==(i-1)/n+1&&h<a[pos])){
			d=(i-1)/n+1;
			h=a[pos];
		}
		if(h+b[pos]>k){
			h1=(h+b[pos])%k;
			d1=d+1;
		}
		else{
			h1=(h+b[pos]);
			d1=d;
		}
		v[i]={d1,h1};
	}
	ll deltad;
	if(v[3*n].second==v[2*n].second){
		for(int i=1;i<=q;i++){
			cin>>x>>y;
			if(x<=3){
				cout<<v[(x-1)*n+y].first<<" "<<v[(x-1)*n+y].second<<"\n";
			}
			else{
				deltad=v[2*n+y].first-v[n+y].first;
				cout<<(x-3)*deltad+v[2*n+y].first<<" "<<v[2*n+y].second<<"\n";
			}
			
		}
	}
	else{
		for(int i=1;i<=q;i++){
			cin>>x>>y;
			if(x<=3){
				cout<<v[(x-1)*n+y].first<<" "<<v[(x-1)*n+y].second<<"\n";
			}
			else{
				ll deltasum=(x-3-1)*sumt;
				deltasum+=pre[y];
				ll tempd;
				tempd=v[3*n].first*k-k+v[3*n].second;
				tempd+=deltasum;
				ll tempt;
				tempt=tempd%k;
				if(tempt==0){
					tempt=k;
					cout<<tempd/k<<" "<<tempt<<"\n";
				}
				else cout<<tempd/k+1<<" "<<tempt<<"\n";
			}
			
		}
		
	}
	
	
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t=1;
	solve();
}
