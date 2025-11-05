#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5+5;
int n,m,k,w,a[maxn],start[maxn];
int red;
vector<int>ans;
int deal(int l,int r){
	if(a[red] > r) return 1;
	if(l>r) return 1;
	
	int cnt=1;
	start[1]=a[red];
	for( ;;){
		red++;
		if(red>=n+1) break;
		if(a[red]>r) break;
		if(a[red]<=start[cnt]+k-1) {
			continue;
		}
		else {
			cnt++;
			start[cnt]=a[red];
		}
	}
	
	int len=r-l+1;
	if(cnt*k>len) return 0;
	start[cnt+1]=r+1;
	for(int i=cnt;i>=1;i--){
		if(start[i]+k-1>=start[i+1]){
			start[i]=start[i+1]-k;
		}
		else break;
	}
	if(start[1]<l) return 0;
	for(int i=1;i<=cnt;i++){
		ans.push_back(start[i]);
	}
	/*
	cout<<"cnt="<<cnt<<"\n";
	for(int i=1;i<=cnt;i++){
		cout<<start[i]<<" ";
	}
	*/
	return 1;
}
void solve(){
	cin>>n>>m>>k>>w;
	
	vector<int>black;
	black.clear();
	ans.clear();
	red=1;
	
	for(int i=1;i<=n;i++) {
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	
	black.push_back(0);
	for(int i=1;i<=m;i++){
		int u;cin>>u;
		black.push_back(u);
	}
	black.push_back(w+1);
	sort(black.begin(),black.end());
	int sz=m+2;
	int flag=1;
	for(int i=0;i<sz-1;i++){
		if(red>=n+1) break;
		if(!deal(black[i]+1,black[i+1]-1)) {
			flag=0;
			break;
		}
	}
	if(flag==0){
		cout<<-1<<"\n";
		return;
	}
	cout<<ans.size()<<"\n";
	for(auto v:ans){
		cout<<v<<" ";
	}
	cout<<"\n";
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		//TODO
		solve();
	}
}
/*

3
5 3 3 20
2 7 9 10 13
4 14 17
2 2 3 7
2 7
4 5
2 1 5 6
3 6
1

3
9 1 3 14
1 3 4 5 6 9 10 11 13
14
9 1 3 14
2 4 5 6 7 10 11 12 14
1
9 1 3 12
1 3 4 5 6 7 8 9 11
12

*/
