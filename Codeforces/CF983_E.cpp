#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+5;
int n,a[N],even2[N],odd2[N],odd[N],even[N],ans[N];
void solve(){
	cin>>n;
	int mx=0;
	for(int i=1;i<=n;i++) cin>>a[i],mx=max(mx,a[i]);
	
	for(int i=0;i<=n+1;i++) even[i]=odd[i]=even2[i]=odd2[i]=0;
	
	for(int i=1;i<=n;i++){
		int d=mx-a[i];
		if(i%2==1){
			even[i+1]+=d;
			even[n+1]-=d;
			odd[1]+=d;
			odd[i]-=d;
		}
		else {
			odd[i+1]+=d;
			odd[n+1]-=d;
			even[2]+=d;
			even[i]-=d;
		}
	}
	
	for(int i=1;i<=n;i++){
		even[i]+=even[i-1];
		int d=even[i];
		if(i%2==0){
			even2[i+2]+=d;
			even2[n+1]-=d;
			odd2[1]+=d;
			odd2[i]-=d;
		}
	}
	
	for(int i=1;i<=n;i++){
		odd[i]+=odd[i-1];
		int d=odd[i];
		if(i%2==1){
			odd2[i+2]+=d;
			odd2[n+1]-=d;
			even2[2]+=d;
			even2[i]-=d;
		}
	}
	
	for(int i=1;i<=n;i++){
		odd2[i]+=odd2[i-1];
		even2[i]+=even2[i-1];
		if(i%2==1) ans[i]=odd2[i];
		else ans[i]=even2[i];
	}
	/*
	cout<<"a="<<'\n';
	for(int i=1;i<=n;i++){
		a[i]+=ans[i]*2;
		int l=i-1,r=i+1;
		if(l==0) l=n;
		if(r==n+1) r=1;
		a[l]+=ans[i];
		a[r]+=ans[i];
	}
	for(int i=1;i<=n;i++) cout<<a[i]<<" ";
	cout<<'\n';
	*/
	for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
	
	cout<<'\n';
}
signed main(){
	int t;cin>>t;
	while(t--){
		//TODO
		solve();
	}
}
