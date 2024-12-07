#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N =3e5+5;
int a[N],sum[N];
int Q(int l,int r){
	if(l>r) return 0;
	return sum[r]-sum[l-1];
}
void solve(){
	int n,m,v;
	cin>>n>>m>>v;
	for(int i=1;i<=n;i++) cin>>a[i],sum[i]=sum[i-1]+a[i];
	
	int sum=0,cnt=0,flag=0;
	map<int,int>pre,suf;
	for(int i=1;i<=n;i++){
		sum+=a[i];
		if(sum>=v){
			cnt++;
			pre[cnt]=i;
			sum=0;
		}
	}
	if(cnt>=m) flag=1;
	sum=0,cnt=0;
	for(int i=n;i>=1;i--){
		sum+=a[i];
		if(sum>=v){
			cnt++;
			suf[cnt]=i;
			sum=0;
		}
	}
	if(cnt>=m) flag=1;
	if(flag==0){
		cout<<"-1"<<"\n";
		return;
	}
	int ans=0;
	for(int i=0;i<=m;i++){
		int l=pre[i];
		if(l==0&&i) break;
		int r=suf[m+1-i-1];
	//	cout<<i<<" ["<<l<<" "<<r<<"]"<<'\n';
		if(r){
			ans=max(ans,Q(l+1,r-1));
		}
		else {
			if(i==m) {
				ans=max(ans,Q(l+1,n));
			}
		}
	}
	cout<<ans<<'\n';
}
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--){
		solve();
	}
}
