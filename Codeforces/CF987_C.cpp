#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n;cin>>n;
	if(n%2==1){
		if(n<101){
			cout<<-1<<'\n';
		}
		else {
			int use=2;
			cout<<1<<" ";
			for(int i=1;i<=17;i++){
				cout<<use<<" "<<use<<" ";
				use++;
			}
			cout<<use<<" ";
			cout<<1<<" ";
			cout<<use+1<<" "<<use+1<<" "<<use<<" ";
			use+=2;
			for(int i=1;i<=30;i++){
				cout<<use<<" "<<use<<" ";
				use++;
			}
			cout<<1<<" ";
			n-=101;
			for(int i=1;i<=n;i+=2){
				cout<<use<<" "<<use<<" ";
				use++;
			}
			cout<<'\n';
		}
	}
	else {
		for(int i=1;i<=n;i+=2){
			cout<<i<<" "<<i<<" ";
		}
		cout<<'\n';
	}
}
int main(){
	int t;cin>>t;
	while(t--){
		//TODO
		solve();
	}
}
