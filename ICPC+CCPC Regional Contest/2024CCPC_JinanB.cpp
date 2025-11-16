#include<bits/stdc++.h>
using namespace std;
int n,col[10],t[10],ans[10],mx=0;
void check(int chose){
	//cout<<chose<<":";
	int p=0;
	for(int i=0;i<=4;i++) p+=col[i];
	
	for(int i=1;i<=chose;i++){
	//	cout<<ans[i]<<" ";
		p-=col[ans[i]];
	}
	//cout<<"\n";
	int ret=0;
	//p:可用的牌
	int love=t[4]+t[5];
	for(int i=1;i<=chose;i++){
		int Col=ans[i];
		int need=5-col[Col];
		if(t[Col]){
			int d=min(min(p,3),need);
			need-=d;
			p-=d;
		}
		if(need){
			if(love){
				int d=min(min(p,love),need);
				need-=d;
				p-=d;
				love-=d;
			}
		}
		if(!need) ret++;
	}
	mx=max(mx,ret);
}
void dfs(int at,int chose){
	if(chose>=4) return;
	if(at==4){
		check(chose);
		return;
	}
	//选
	ans[chose+1]=at;
	dfs(at+1,chose+1);
	dfs(at+1,chose);
}
void solve(){
	cin>>n;
	/**
	 * init
	  int n,col[10],t[10],ans[10],mx=0;
	 */
	
	for(int i=0;i<=8;i++) col[i]=t[i]=ans[i]=0;
	mx=0;
	
	for(int i=1;i<=n;i++){
		string s;cin>>s;
		int c=s[1];
		if(c=='D') col[0]++;
		if(c=='C') col[1]++;
		if(c=='H') col[2]++;
		if(c=='S') col[3]++;
	}
	for(int i=0;i<6;i++) cin>>t[i];
	int ready=0;
	for(int i=0;i<=3;i++){
		ready+=col[i]/5;
		col[i]%=5;
	}
	dfs(0,0);
	cout<<ready+mx<<"\n";
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t=1;
	cin>>t;
	while(t--){
		//TODO
		solve();
	}
}
/*
 
3
1
1D
 1 0 0 0 1 1
5
1D 2D 3D 1C 2C
0 0 1 0 1 1
5
1D 2D 3D 1C 1H
0 0 1 0 0 1
 */
