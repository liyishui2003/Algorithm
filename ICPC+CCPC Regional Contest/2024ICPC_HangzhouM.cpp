#include<bits/stdc++.h>
using namespace std;
#define ing long long
typedef long long ll;
ll n,k,top,a[5*100005];
int sta[5*100005],f[5*100005];
int check(int x){
	for(int i=1;i<=n;i++){
		//	cout<<i<<" "<<f[i]<<"\n";
		if((a[i]+x)%(a[f[i]]+x)) return 0;
	}
	return 1;
}
void solve(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	//特判n=1
	if(n==1){
		cout<<k<<" "<<(1+k)*k/2<<"\n";
		return;
	}
	set<int>fac;
	ll mx=-1,mi=INT_MAX;
	for(int i=1;i<=n;i++){
		mx=max(mx,a[i]);
		mi=min(mi,a[i]);
	}
	
	if(mx==mi){
		cout<<k<<" "<<(1+k)*k/2<<"\n";
		return;
	}
	int up=sqrt(mx-mi);
	for(int i=1;i<=up;i++){
		if((mx-mi)%i) continue;
		int a=(mx-mi)/i;
		if(a-mi>0){
			fac.insert(a-mi);
		}
		else fac.insert(a);
		int b=(mx-mi)/a;
		if(b-mi>0){
			fac.insert(b-mi);
		}
		else fac.insert(b);
	}	
	
	top=1;
	sta[1]=f[1]=1;
	for(int i=2;i<=n;i++){
		if(a[i]>=a[sta[top]]){
			f[i]=sta[top];
			top++;
			sta[top]=i;
		}
		else {
			int last=-1;
			while(a[i]<=a[sta[top]]){
				last=sta[top];
				top--;
				if(top==0) break;
			}
			if(top==0) f[i]=i;
			else f[i]=sta[top];
			f[last]=i;
			top++;
			sta[top]=i;
		}
	}
	ll sum=0,tot=0;
	for(auto v:fac){
		if(v>k || v==0) continue;
		int flag=check(v);
		if(flag==1){
			sum+=v;
			tot++;
		}
	}
	cout<<tot<<" "<<sum<<'\n';
}
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--){
		solve();
	}
}
