#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6+5;
int a[N],pos[N];
void solve(){
	int n,q;cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>a[i];
	string s;cin>>s;
	s=" "+s;
	int mx=0,id=0;
	for(int i=1;i<=n;i++){
		mx=max(mx,a[i]);
		if(mx==i){
			while(id<i){
				id++;
				pos[id]=i;
			}
		}
	}
	int cnt=0;
	for(int i=1;i<n;i++){
		if(s[i]=='L'&&s[i+1]=='R'&&pos[i]==pos[i+1]){
			cnt++;
		}
	}
	
	while(q--){
		
		int i;cin>>i;
		if(s[i]=='R'&&s[i-1]=='L'&&pos[i]==pos[i-1]){
			cnt--;
		}
		if(s[i]=='L'&&s[i+1]=='R'&&pos[i]==pos[i+1]){
			cnt--;
		}
		if(s[i]=='L') s[i]='R';
		else s[i]='L';
		
		if(s[i]=='R'&&s[i-1]=='L'&&pos[i]==pos[i-1]){
			cnt++;
		}
		if(s[i]=='L'&&s[i+1]=='R'&&pos[i]==pos[i+1]){
			cnt++;
		}
		
		if(cnt) cout<<"NO"<<'\n';
		else cout<<"YES"<<'\n';
	}
}
signed main(){
	int t;cin>>t;
	while(t--){
		//TODO
		solve();
	}
}
