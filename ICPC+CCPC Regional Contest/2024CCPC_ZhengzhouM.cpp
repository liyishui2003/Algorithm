#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int maxn = 1e5+5;
int n,k;
double a[maxn];
int check(double x){
	double tot=0;
	for(int i=1;i<=n;i++){
		double pi=1-(1/(a[i]*x+1));
		tot+=pi;
	}
	return (tot>=k);
}
void solve(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		int u;cin>>u;
		a[i]=u;
	}
	double  l=0,r=1e6,ans=-1;
	for(int i=1;i<=200;i++){
		double mid= (l+r)/2;
		if(check(mid)){
			ans=mid;
			r=mid;
		}
		else l=mid;
	}
	for(int i=1;i<=n;i++){
		double pi=1-(1/(a[i]*ans+1));
		cout<<fixed<<setprecision(14)<<pi<<"\n";
	}
}
signed main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t=1;
	while(t--){
		solve();
	}
}
