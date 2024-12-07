#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+5;
int n,cnt,mx;
char a[N];
void dfs(int u,int sum,int cnt1,int cnt0,int user){
	if(u>(n+1)/2+1 && user==0) return;
	if( cnt1> mx || cnt0> mx ) return;
	if(u==n+1){
		if(abs(cnt1-cnt0)>1) return;
		//	cout<<sum<<" "<<cnt1<<" "<<cnt0<<'\n';
		cnt++;
		for(int i=1;i<=n;i++){
			cout<<a[i];
		}
		cout<<'\n';
		if(cnt==100){
			exit(0);
		}
		return;
	}
	a[u]='b';
	sum^=0;
	if(sum==0) cnt0++;
	else cnt1++;
	dfs(u+1,sum,cnt1,cnt0,user);
	if(sum==0) cnt0--;
	else cnt1--;
	sum^=0;
	
	a[u]='r';
	sum^=1;
	if(sum==0) cnt0++;
	else cnt1++;
	dfs(u+1,sum,cnt1,cnt0,user+1);
	if(sum==0) cnt0--;
	else cnt1--;
	sum^=1;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n;
	long long tot;
	long long odd=(n+1)/2;
	long long even=n/2;
	tot=odd*(odd-1)/2+even*(even-1)/2+n;
	cout<<tot<<'\n';
	
	if(n%2==1) mx=(n+1)/2;
	else mx=n/2+1;
	dfs(1,0,0,1,0);
}
