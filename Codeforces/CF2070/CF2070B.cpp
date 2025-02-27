#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(){
	ll n,x,k;cin>>n>>x>>k;
	string s;cin>>s;
	int getZero=-1;
	for(int pos=x,cnt=0;cnt<n;cnt++){
		if(s[cnt]=='L') pos--;
		else pos++;
		if(pos == 0 ) {
			getZero = cnt;
			break;
		}
	}
	
	if(getZero==-1){
		cout<<0<<endl;
		return;
	}
	
	k-=(getZero+1);// left k
	
	getZero = -1;
	for(int pos=0,cnt=0;cnt<n;cnt++){
		if(s[cnt]=='L') pos--;
		else pos++;
		if(pos == 0 ) {
			getZero = cnt;
			break;
		}
	}
	if(getZero == -1){
		cout<<1<<endl;
		return;
	}
	cout<<1+(k/(getZero+1))<<endl;
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
