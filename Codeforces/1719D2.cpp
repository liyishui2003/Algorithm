#include<bits/stdc++.h>
using namespace std;
int solve(int a[],int n){
	int cnt=0;
	for(int i=1;i<=n; ){
		//	cout<<i<<" "<<a[i]<<endl;
		if(i>n) break;
		if(a[i]==0) {
			i++;
		}
		else {
			if(i+1<=n){
				if(a[i]==a[i+1]) {
					cnt++;
					a[i]=a[i+1]=0;
					i+=2;
				}
				else a[i+1]^=a[i],a[i]=0,cnt++,i++;
			}
			else cnt++,i++;
		}
		//	cout<<i<<" ? "<<a[i]<<endl;
	}
	return cnt;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		int a[n+5],b[n+5];
		for(int i=1;i<=n;i++) cin>>a[i],b[n-i+1]=a[i];
		cout<<min(solve(a,n),solve(b,n))<<endl;
	}
}
