#include<bits/stdc++.h>
using namespace std;
int a[505][505];
void solve(){
	
	int n;cin>>n;
	
	vector<pair<int,int>>out;
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
			a[i][j]=j,ans+=j;
		out.push_back({1,i});
	}
		
	
	int tot=(1+n)*n/2;
	int p=1;
	while(out.size()<2*n){
		
		int flag=1;
		if(p==1){
			for(int i=1;i<=n;i++){	
				int sum=0;
				for(int j=1;j<=n;j++) sum+=a[j][i];
				if(sum<=tot&&((int)out.size()<2*n)){
					ans-=sum;ans+=tot;
					out.push_back({2,i});
					for(int j=1;j<=n;j++) a[j][i]=j;
				}
			}
		}
		else {
			for(int i=1;i<=n;i++){
				int sum=0;
				for(int j=1;j<=n;j++) sum+=a[i][j];
				if(sum<=tot&&((int)out.size()<2*n)) {
					ans-=sum;ans+=tot;
					out.push_back({1,i});
					for(int j=1;j<=n;j++) a[i][j]=j;
				}
			}
		}
		p^=1;
	}
	
	cout<<ans<<" "<<out.size()<<endl;
	for(auto v:out){
		cout<<v.first<<" "<<v.second<<" ";
		for(int i=1;i<=n;i++) cout<<i<<" ";
		cout<<endl;
	}
}
int main(){
	
	
	cout<<(1<<18);
	int t;cin>>t;while(t--){
		solve();
	}
}
