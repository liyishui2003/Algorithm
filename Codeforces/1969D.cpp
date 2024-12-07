#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+5;
int n,k,a[N],b[N],sum[N];
//不要随便用不可重集！！
struct node{
	int b,a;
}f[N];
bool cmp(node x,node y){
	return x.b>y.b;
}
void solve(){
	cin>>n>>k;
	int cnt=0;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		cin>>b[i];
		cnt++;
		f[cnt]=(node){b[i],a[i]};
	}
	
	if(k==0){
		int tot=0;
		for(int i=1;i<=n;i++){
			if(b[i]>a[i]) tot+=b[i]-a[i];
		}
		cout<<tot<<"\n";
		return ;
	}
	sort(f+1,f+cnt+1,cmp);
	multiset<int>s;
	int tot=0;
	for(int i=1;i<=k;i++){
		tot+=-f[i].a;
		s.insert(-f[i].a);
	}
	sum[k]=tot;
	for(int i=k+1;i<=cnt;i++){
		if(-f[i].a>*(s.begin())){
			auto it=s.lower_bound(*s.begin());
			tot-=*(s.begin());
			s.erase(it);
			s.insert(-f[i].a);
			tot+=-f[i].a;
		}
		sum[i]=tot;
	}
	int afx=0;
	int ans=0;
	for(int i=cnt;i>=k;i--){
		ans=max(ans,sum[i]+afx);
		afx+=max(0*1ll,f[i].b-f[i].a);
	}
	cout<<ans<<"\n";
}
signed main(){
	int t;cin>>t;
	while(t--){
		solve();
	}
}
