#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
const int N=1e6+5;
int lowbit(int i) { return i&(-i); }
struct bit{
	int c[N],n;
	void init(){ for(int i=1;i<=n;i++) c[i]=0; }
	int qsum(int x){
		if(x<=0) return 0;
		int ans=0;x=min(x,n);while(x) { ans+=c[x];x-=lowbit(x); } return ans;
	}
	void add(int x){
		while(x<=n) { c[x]+=1;x+=lowbit(x); }
	}
}Q;
int p[N],q[N];
void solve(){
	int n,k;cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>p[i];
	for(int i=1;i<=k;i++) cin>>q[i];
	int pair_p=0;
	Q.n=k;
	Q.init();
	for(int i=1;i<=k;i++){
		q[i]++;
		pair_p+=i-1-Q.qsum(q[i]);
		pair_p%=mod;
		Q.add(q[i]);
	}
	int extra_20=0;
	vector<int>sum(41);
	for(int i=-20;i<=20;i++){
		for(int j=0;j<k;j++){
			int to=i+j;
			if(to<=k-1&&to>=0) sum[i+20]=(sum[i+20]+1)%mod;
		}
	}
	for(int i=0;i<k;i++){
		if(i-21>=0) extra_20+=i-20,extra_20%=mod;
	}
	int ans=0;
	for(int x=-20;x<=20;x++){
		
		Q.n=2*n-1;
		Q.init();
		for(int i=1;i<=n;i++){
			int tmp=p[i];
			if(x>=0) for(int _=1;_<=x;_++) tmp=min(tmp<<1,2*n-1);
			else {
				double __=p[i];
				for(int _=1;_<=-x;_++) __/=2;
				tmp=ceil(__);
			}
			// >tmp
			if(tmp!=2*n-1){
				ans+=(i-1-Q.qsum(tmp-1))*sum[x+20]%mod;
				ans%=mod;	
			}
			Q.add(p[i]);
		}
		
	}
	ans+=n*pair_p%mod;
	ans%=mod;
	ans+=(extra_20*n*(n-1)/2)%mod;
	ans%=mod;
	cout<<ans<<endl;
	
}
signed main(){
//	freopen("lys.in","r",stdin);
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t;cin>>t;while(t--){
		solve();
	}
}
