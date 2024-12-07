#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+5;
int a[N];
void solve(){
	int n,k;cin>>n>>k;
	map<int,int>mp;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mp[a[i]]++;
	}
	sort(a+1,a+n+1);
	int len=unique(a+1,a+n+1)-(a+1);
	if(k<=a[1]*n){
		cout<<k<<'\n';
		return;
	}
	int tot=0,use=0;
	tot+=a[1]*n;
	k-=a[1]*n;
	for(int i=2;i<=len;i++){
		tot+=mp[a[i-1]];// worse case
		use+=mp[a[i-1]];// be deleted
		if(k>(n-use)*(a[i]-a[i-1])){
			k-=(n-use)*(a[i]-a[i-1]);
			tot+=(n-use)*(a[i]-a[i-1]);
		}
		else {
			tot+=k;
			break;
		}
	}
	cout<<tot<<'\n';
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
