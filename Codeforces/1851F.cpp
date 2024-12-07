#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
pair<int,int>a[N];
void solve(){
	int n,k;cin>>n>>k;
	for(int i=1;i<=n;i++) {
		int c;cin>>c;a[i]={c,i};
	}
	
	sort(a+1,a+n+1);
	
	int mi=INT_MAX,pos=-1;
	for(int i=1;i<n;i++){
		int tmp=a[i].first^a[i+1].first;
		if(tmp<mi){
			mi=tmp;pos=i;
		}
	}
	k--;
	int x=0,c=a[pos].first,d=a[pos+1].first;
	for(int bit=k;bit>=0;bit--){
		if( ((c>>bit)&1) == ((d>>bit)&1) ){
		   	if( (c>>bit)&1 ) {}
			else x+=(1<<bit);
		}
	}
	cout<<a[pos].second<<" "<<a[pos+1].second<<" "<<x<<endl;
}
int main(){
	int t;cin>>t;
	while(t--){
		solve();
	}
}
