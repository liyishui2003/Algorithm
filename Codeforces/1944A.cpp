#include<bits/stdc++.h>
using namespace std;
#define int long long 
void solve(){
	int n;cin>>n;
	int a[n+5];for(int i=1;i<=n;i++) a[i]=i-1;
	int mx=-1,mx2=-1;
	pair<int,int>q;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(i!=j) {
				mx=max(mx,a[i]^a[j]);
			    if(mx==(a[i]^a[j])) q={i,j}; 
			}
				
				
	
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(i!=j) mx2=max(mx2,a[i]|a[j]);
	
	cout<<"mx: "<<mx<<" q:"<<q.first<<" "<<q.second<<endl;
	cout<<"| "<<(a[q.first]|a[q.second])<<" ^ "<<(a[q.first]^a[q.second])<<endl;
}
signed main(){
	int t;cin>>t;while(t--)solve();
}
