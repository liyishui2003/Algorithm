#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n,k;
	cin>>n>>k;
	string tmp;
	cin>>tmp;
	k=min(min(k,7),n);
	int ans=0;
	for(int i=0;i<=k;i++){
		int ret=0;
		//nanjing
		for(int j=6+i;j<n+i;j++){
			if(tmp[j]=='g' && tmp[j-1]=='n' && tmp[j-2]== 'i'
			 &&tmp[j-3]=='j' &&tmp[j-4]=='n' &&tmp[j-5]=='a'
			 &&tmp[j-6]=='n')
				ret++;
		}
		tmp=tmp+tmp[i];
		ans=max(ans,ret);
	}
	cout<<ans<<"\n";
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		//TODO
		solve();
	}
}
