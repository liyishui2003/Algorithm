#include<bits/stdc++.h>
using namespace std;
const int N = 20;
int n,a[N];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	
	int ans=0;
	vector<int>bre;
	bre.push_back(0);
	for(int i=1;i<=n;i++){
		if(a[i]>=n*n){
			bre.push_back(i);
			ans+=a[i];
		}
	}
	bre.push_back(n+1);
	vector<pair<int,int>>sol;
	for(int i=0;i<bre.size()-1;i++){
		int l=bre[i]+1,r=bre[i+1]-1;
		cout<<"["<<l<<","<<r<<"]"<<"\n";
		if(l<=r){
			int len=r-l;
			ans+=(1+len)*len/2;
			for(int j=l;j<=r;j++)
				sol.push_back({l,j});
		}
	}
	cout<<ans<<" "<<sol.size()<<"\n";
	for(auto v:sol){
		cout<<v.first<<" "<<v.second<<"\n";
	}
	
}
