#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N =3e5+5;
int q[N],j[N],k[N],vis[N],pre[N],bel[N];
void solve(){
	int n;cin>>n;
	for(int i=1;i<=n;i++) vis[i]=0,pre[i]=bel[i]=0;
	set<pair<int,int>>s1,s2,s3;
	set<int>use;
	use.insert(1);
	vis[1]=1;
	for(int i=1;i<=n;i++){
		cin>>q[i];
		s1.insert({q[i],i});
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		s2.insert({k[i],i});
	}
	for(int i=1;i<=n;i++){
		cin>>j[i];
		s3.insert({j[i],i});
	}

	while(!use.empty()){
		auto v=*(use.begin());
		vis[v]=1;
		
		while(!s1.empty()){
			auto u=*s1.begin();
			int val=u.first;
			if(val>=q[v])  break;
			else {
				int pos=u.second;
				if(pos>v) {
					use.insert(pos);
					pre[pos]=v,bel[pos]=1;
				}
				s1.erase(s1.begin());
			}
		}
		
		while(!s2.empty()){
			auto u=*s2.begin();
			int val=u.first;
			if(val>=k[v])  break;
			else {
				int pos=u.second;
				if(pos>v) {
					use.insert(pos);
					pre[pos]=v,bel[pos]=2;
				}
				s2.erase(s2.begin());
			}
		}
		
		while(!s3.empty()){
			auto u=*s3.begin();
			int val=u.first;
			if(val>=j[v])  break;
			else {
				int pos=u.second;
				if(pos>v) {
					use.insert(pos);
					pre[pos]=v,bel[pos]=3;
				}
				s3.erase(s3.begin());
			}
		}
		
		use.erase(v);
	}
	
	if(vis[n]) cout<<"YES"<<"\n";
	else {
		cout<<"NO"<<'\n';
		return;
	}
	vector<pair<int,int>>ans;
	int at=n;
	while(at){
		if(!pre[at]) break;
		ans.push_back({pre[at],bel[at]});
	//	cout<<pre[at]<<" "<<bel[at]<<"\n";
		at=pre[at]; 
	}
	cout<<ans.size()<<'\n';
	for(int i=ans.size()-1;i>=0;i--){
		int pos=ans[i].first,bel=ans[i].second;
		
		if(bel==1) cout<<"q ";
		else if(bel==2) cout<<"k ";
		else if(bel==3) cout<<"j ";
		
		if(i==0) cout<<n<<'\n';
		else cout<<ans[i-1].first<<'\n';
	}
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
