#include<bits/stdc++.h>
using namespace std;
#define int long long 
int n,k;
const int N = 2e5+5;
int to[N],col[N],blo[N],pa[N][20],ans[N];
string s;
stack<int>sta;
void dfs(int u){
	if(col[u]) return;
	sta.push(u);
	col[u]=1;
	dfs(to[u]);
}
void solve(){
	cin>>n>>k;
	cin>>s;
	s=" "+s;
	for(int i=1;i<=n;i++){
		if(i%2==1)	to[i]=(i+1)/2;
		else to[i]=(n+1)/2+i/2;
	}
	int dfn=0;
	for(int i=1;i<=n;i++){
		if(col[i]) continue;
		dfn++;
		while(!sta.empty()){
			sta.pop();
		}
		dfs(i);
		int sz=sta.size();
		while(!sta.empty()){
			blo[sta.top()]=sz;
			sta.pop();
		}
	}
	//	cout<<666<<'\n';
	for(int i=1;i<=n;i++){
		pa[i][0]=to[i];
	}
	for(int i=1;i<=19;i++){
		for(int j=1;j+(1<<i)-1<=n;j++){
			pa[j][i]=pa[pa[j][i-1]][i-1];
		}
	}
	//cout<<666<<'\n';
	for(int i=1;i<=n;i++){
		if(n%2==0&&i%2==0) continue; 
		int kk=k%blo[i];
		//	cout<<i<<" "<<blo[i]<<'\n';
		int at=i;
		for(int j=19;j>=0;j--){
			if(kk>=(1<<j)){
				at=pa[at][j];
				kk-=(1<<j);
			}
		}
		//	cout<<"i= "<<i<<" at= "<<at<<'\n';
		ans[at]=i;
	}
	if(n%2==0){
		int cnt=0;
		while(1){
			for(int i=1;i<=n;i++) {
				if(ans[i]==0) continue;
				cout<<s[ans[i]];
				cnt++;
			}	
			if(cnt==n) break;
		}
	}
	else {
		for(int i=1;i<=n;i++) {
			if(ans[i]==0) continue;
			cout<<s[ans[i]];
		}
	}
	cout<<'\n';
}
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t=1;
	while(t--){
		solve();
	}
}
