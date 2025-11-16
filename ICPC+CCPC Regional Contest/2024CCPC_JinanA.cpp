#include<bits/stdc++.h>
using namespace std;
int n,m,k;
char a[205][2005];
void solve(){
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)
		{
			for(int h=1;h<=k;h++){
				cin>>a[i][(j-1)*k+h];
			}	
		}
	}
	string tmp="";
	vector<pair<int,int>>ret;
	for(int i=1;i<=k;i++) tmp=tmp+a[1][i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)
		{
			if(i==1&& j==1) continue;
			int cnt=0;
			for(int h=1;h<=k;h++){
				cnt+=(a[i][(j-1)*k+h]==tmp[h-1]);
			}
			if(cnt!=k) {
				ret.push_back(make_pair(i,j));
			} 
		}
	}
	if(ret.size()==1){
		cout<<ret[0].first<<" "<<ret[0].second<<"\n";
	}
	else cout<<1<<" "<<1<<"\n";
	
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t=1;
	while(t--){
		//TODO
		solve();
	}
}
