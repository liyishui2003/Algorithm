#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
int n,x[maxn],y[maxn],z[maxn],c[maxn],sum[maxn];
void solve(){
	cin>>n;
	c[0]=sum[0]=0;
	map<int,int>cntx,cnty,cntz;
	for(int i=1;i<=n;i++){
		cin>>x[i]>>y[i]>>z[i];
		cntx[x[i]]++;
		cnty[y[i]]++;
		cntz[z[i]]++;
		
		c[i]=sum[i]=0;
	}
	
	for(int i=1;i<=n;i++){
		int midu=max(cntx[x[i]],max(cnty[y[i]],cntz[z[i]]));
		midu--;
		c[midu+1]++;
	}
	
	for(int i=0;i<=n-1;i++){
		if(i) sum[i]=sum[i-1]+c[i];
		cout<<sum[i]<<" ";
	}
	cout<<"\n";
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t=1;
	cin>>t;
	while(t--){
		//TODO
		solve();
	}
}
/*
2
5
1 1 1
1 2 3
3 1 2
3 2 1
1 1 1
4
1 1 1
1 1 1
2 2 2
3 3 3
*/
