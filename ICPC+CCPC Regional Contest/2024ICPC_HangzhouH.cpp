#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,k,len[100005],l[100005],r[100005],f[100005];
struct seg{
	int l,r,len;
}a[100005];
bool cmp(seg a,seg b){
	return a.len<b.len;
}
void solve(){
	cin>>n>>k;
	for(int i=1;i<=n;i++) f[i]=0;
	
	for(int i=1;i<=k;i++){
		int l,r;cin>>l>>r;
		a[i]=(seg){l,r,r-l+1};
	}
	sort(a+1,a+k+1,cmp);
	
	//判断无解
	int mx=a[k].len,cntmx=0;
	for(int i=1;i<=k;i++){
		if(a[i].len==mx) {
			cntmx++;
		}
	}
	
	if(cntmx>1 && a[1].len>=mx-1){
		cout<<"IMPOSSIBLE\n";
		return;
	}
	
	int root=a[k].l;//指定最后的最长链条的顶端为root;
	
	//每条链条内部连
	for(int j=1;j<=k;j++){
		for(int i=a[j].l+1,pa=a[j].l;i<=a[j].r;i++,pa++){
			f[i]=pa;
		}	
	}
	
	//连主链
	if(cntmx>1){
		//一定有1条最短链，1条最长链
		if(n>=2) {
			
			if(a[1].len>=mx-1)  {
				cout<<"IMPOSSIBLE\n";
				return;
			}
			
			f[a[1].l]=root+1;	
		}
		
		for(int i=2;i<=k-1;i++)
			f[a[i].l]=root;	
	}
	else {
		for(int i=1;i<=k-1;i++)
			f[a[i].l]=root;	
	}
	
	for(int i=1;i<=n;i++){
		cout<<f[i]<<" ";
	}
	cout<<"\n";
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--){
		//TODO
		solve();
	}
}
/*
3
5 3
1 2
3 4
5 5
8 4
1 2
3 5 
6 7
8 8
13 4
1 2
3 6
7 10
11 13


*/
