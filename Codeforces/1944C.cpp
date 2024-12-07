#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n,k;cin>>n;
	int a[n+5]={0};
	vector<int>cnt(n+5);
	for(int i=1;i<=n;i++) cin>>a[i],cnt[a[i]]++;
	int die=0;
	for(int i=0;i<=n;i++){
		if(cnt[i]==0){
			cout<<i<<endl;return;
		}
		if(cnt[i]!=1) continue;
		die++;
		if(die==2) {
			cout<<i<<endl;return;
		}
	}
}
int main(){
	int t;cin>>t;while(t--)solve();
}
