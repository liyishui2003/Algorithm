#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[105][105];
void solve(){
	int n;cin>>n;
	memset(a,0,sizeof a);
	for(int i=1;i<=n;i++){
		int w,h;cin>>w>>h;
		for(int j=1;j<=h;j++)
			for(int k=1;k<=w;k++){
				a[j][k]=1;
			}
	}
	
	int ans=0;
	for(int i=1;i<=100;i++){
		for(int j=1;j<=100;j++){
			if(a[i][j]==0) continue;
			
			if(a[i-1][j]==0) ans++;
			if(a[i][j-1]==0) ans++;
			if(a[i][j+1]==0) ans++;
			if(a[i+1][j]==0) ans++;
		}
	}
	cout<<ans<<'\n';
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
