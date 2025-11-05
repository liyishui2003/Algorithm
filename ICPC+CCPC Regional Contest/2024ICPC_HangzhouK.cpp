#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int row[100005],p[100005],ans[100005];
void solve(){
	cin>>n>>m>>k;
	for(int i=1;i<=n*m;i++){
		cin>>p[i];
	}
	if(k>=m){
		cout<<m<<"\n";
		return;
	}
	for(int i=1;i<=n+3;i++) row[i]=0,ans[i]=INT_MAX;
	
	int x=0;
	for(int i=1;i<=n*m;i++){
		int r,c=p[i]%m;
		if(c==0) c=m;
		if(p[i]%m==0) r=p[i]/m;
		else r=p[i]/m+1;
		
		row[r]++;//当前行
		x++;//当前总操作
		
		//当前行够保底了
		if(row[r]==m-k){
			int z=x-row[r];//其它行能给的
			if(z>=k){
				ans[r]=x;
			}
			else {
				ans[r]=x+k-z;
			}
		}
	}
	int ret=INT_MAX;
	for(int i=1;i<=n;i++){
		ret=min(ret,ans[i]);
	}
	cout<<ret<<"\n";
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--){
		//TODO
		solve();
	}
}
/*
3
3 5 2
1 4 13 6 8 11 14 2 7 10 3 15 9 5 12
2 3 0
1 6 4 3 5 2
2 3 1000000000
1 2 3 4 5 6


3
3 5 2
1 2 3 6 7 11 12 13 14 15 8 9 10 5 4
3 5 2
1 2 6 7 3 11 12 13 14 15 8 9 10 5 4 
3 5 1
1 2 6 7 11 12 3 13 14 15 8 9 10 5 4

2
3 5 3
6 11 12 7 8 9 10 1 2 3 4 5 13 14 15
3 5 1
1 6 11 12 13 14 2 3 4 5 7 8 9 10 15

*/
