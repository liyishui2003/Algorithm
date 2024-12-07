#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6+5;
int a[N],vis[N],mx_[N],suf[N],ans[N];
int query1(int l, int r)
{
	if(l>r) return 0;
	return mx_[r];
}
void solve(){
	int n;cin>>n;
	map<int,int>last;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		vis[i]=0;
		mx_[i]=max(mx_[i-1],a[i]);
		last[a[i]]=i;
		ans[i]=0;
	}

	for(int i=1;i<=n;i++){
		if(last[i]==0){
			suf[i]=suf[i-1];
		}
		else suf[i]=max(suf[i-1],last[i]);
	}
	
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		int mx=max(a[i],mx_[i-1]);
		stack<int>s;
		s.push(i);
		//cout<<i<<" ="<<'\n';
		while(1){
			int to=suf[mx-1];
		//	cout<<"to= "<<to<<" "<<mx<<'\n';
			if(query1(1,to-1)==mx) break;
			if(to>i){
				mx=max(mx,query1(1,to-1));
				if(vis[to]) {
					mx=max(mx,ans[to]);
					continue;
				}
				else vis[to]=1;
				s.push(to);
			}
			else if(vis[to]||to==0) {break;}
		}
		ans[i]=mx;
		while(!s.empty()){
			int u=s.top();
			vis[u]=1;
			ans[u]=mx;
			s.pop();
		}
		
	}
	for(int i=1;i<=n;i++) cout<<ans[i]<<' ';
	cout<<'\n';
}
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--){
		//TODO
		solve();
	}
}
