#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
int n,pa[N];
int ask(int a,int b){
	cout<<"? "<<a<<" "<<b<<'\n';
	fflush(stdout);
	int ans;
	cin>>ans;
	return ans; 
}
void solve(){
	cin>>n;
	int p=2,firchi;
	while(1){
		if(ask(1,p)==0){
			firchi=p;
			break;
		}
		else p++;
	}
	set<pair<int,int>>s;
	for(int i=2;i<=firchi-1;i++){
		pa[i]=0;
		s.insert({1,i});
	}
	s.insert({2,firchi});
	pa[firchi]=1;
	for(int i=firchi+1;i<=n-1;i++){
		while(1){
			int v=(*(s.begin())).second,dep=(*(s.begin())).second;
			if(ask(v,i)==0){
				pa[i]=v;
				s.erase(*s.begin());
				s.insert({dep+1,i});
				break;
			}
			else s.erase(*s.begin());
		}
	}
	cout<<"! ";
	for(int i=1;i<=n-1;i++) cout<<pa[i]<<" ";
	cout<<'\n';
	fflush(stdout);
}
int main(){
	int t;cin>>t;
	while(t--){
		solve();
	}
}
