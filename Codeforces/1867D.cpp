#include<bits/stdc++.h>
using namespace std;
bool solve(){
	int n,k;cin>>n>>k;vector<int>a(n+5);for(int i=1;i<=n;i++) cin>>a[i];
	if(k==1){
		for(int i=1;i<=n;i++) if(a[i]!=i) return false;
		return true;
	}
	vector<int>vis(n+5),cnt(n+5);
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		int j,id=0;
		for(j=i;vis[j]==0;j=a[j]){
			cnt[j]=++id;vis[j]=i;
		}
		if(vis[j]!=i) continue;
		if(id-cnt[j]+1!=k) {
		//	cout<<id<<" "<<i<<endl;
			return false;
		}
	}
	return true;
}
int main(){int t;cin>>t;while(t--){ if(solve()) cout<<"Yes"<<"\n";else cout<<"No"<<"\n";};}
