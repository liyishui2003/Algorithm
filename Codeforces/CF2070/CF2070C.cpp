#include<bits/stdc++.h>
using namespace std;
const int N = 3e5+5;
int n,k,a[N],b[N],use[N];
string s;
bool check(int x){
	for(int i=1;i<=n;i++){
		if(a[i] > x){
			if(s[i-1] == 'R') use[i]=0;
			else use[i] = 1;
		}
		else use[i]=2;
	}
	
	for(int i=1;i<=n;i++){
		if(use[i-1]==1 && use[i]==2) use[i]=1;
		if(use[i-1]==0 && use[i]==2) use[i]=0;
	}
	int ans=0;
	use[0]=0;
	for(int i=1;i<=n;i++){
		if(use[i-1]==0 && use[i]==1) ans++;
	}
	/*
	cout<<"x = "<<x<<endl;
	for(int i=1;i<=n;i++){
		cout<<use[i];
	}
	*/
	return ans<=k;
}
void solve(){
	cin>>n>>k;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	sort(b+1,b+n+1);
	int l=0,r=n,ans=-1;
	while(l<=r){
		int mid= (l+r)>>1;
	//	cout<<l<<" "<<r<<" "<<b[mid]<<endl;
		if(check(b[mid])){
			ans = mid;
			r = mid-1;
		}
		else l = mid + 1;
	}
	cout<<b[ans]<<endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	int t;
	cin>>t;
	while(t--){
		solve();
	}
}
