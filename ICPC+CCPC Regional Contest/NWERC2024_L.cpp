#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int a[N],b[N],lef[N];
int n,m,x,y;
int check(int mid){
	for(int i=1;i<=n;i++){
		if(i<=mid) lef[i]=y;
		else lef[i]=x;
	}
	int p=1;
	for(int i=1;i<=m;i++){
		if(lef[p]>0&&a[p]>=b[i]){
			lef[p]--;
		}
		else {
			while(lef[p]==0||a[p]<b[i]){
				p++;
				if(p>n) break;
			}
			if(p>n) return 0;
			lef[p]--;
		}
	}
	return 1;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>x>>y;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=m;i++) cin>>b[i];
	
	sort(a+1,a+n+1);
	sort(b+1,b+m+1);
	int l=0,r=n,ans=-1;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid)){
			ans=mid;
			l=mid+1;
		}
		else r=mid-1;
	}
	if(ans!=-1) cout<<ans<<'\n';
	else cout<<"impossible";
}
