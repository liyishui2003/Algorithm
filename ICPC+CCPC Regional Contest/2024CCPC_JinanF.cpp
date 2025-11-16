#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 998244353;
const int maxn = 2e5+10;
int fac[maxn],inv[maxn];
int dp[100005][20];
int n,m;
int power(int a,int b,int p){
	if(b==0) return 1;
	if(a==0) return 0;
	int res=1;
	a%=p;
	while(b){
		if(b&1) res=(res*a)%p;
		b>>=1;
		a=a*a%p;
	}
	return res;
}
int nCr(int n,int r,int p){
	if(r>n || r<0 || n<0) return 0;
	if(n==r) return 1;
	if(r==0) return 1;
	return ((fac[n]*inv[r]%p)*inv[n-r])%p;
}
void pre(){
	fac[0]=1;
	inv[0]=1;
	for(int i=1;i<maxn;i++) fac[i]=fac[i-1]*i%mod;
	for(int i=1;i<maxn;i++) 
		inv[i]=power(fac[i],mod-2,mod);
}
void solve(){
	cin>>m>>n;
	int ans=0;
	for(int i=1;i<=m;i++){
		int ret=0;
		for(int j=1;j<=17;j++){
			int add;
			int bs=m/i-1;
			add=dp[i][j]*nCr(bs,n-j,mod);
			ret=(ret+add)%mod;
		}
		int tot=nCr(m-1,n-1,mod);
		tot=(tot-ret+mod)%mod;
		ans=(ans+tot)%mod;
	}
	cout<<ans<<"\n";
}
signed main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	memset(dp,0,sizeof dp);
	dp[1][1]=1;
	for(int i=2;i<=100000;i++){
		int up=sqrt(i);
		//特判1,i
		dp[i][2]=1;//1,i
		dp[i][1]=1;//i	
		for(int j=2;j<=up;j++){
			if(i%j==0) {
				int a=j;
				for(int k=2;k<=17;k++){
					dp[i][k]+=dp[a][k-1];
					dp[i][k]%=mod;
				}
				
				int b=i/a;
				if(b!=a){
					for(int k=2;k<=17;k++){
						dp[i][k]+=dp[b][k-1];
						dp[i][k]%=mod;
					}
				}
			}
		}
	}
	pre();
	
	int t=1;
	//cin>>t;
	while(t--){
		//TODO
		solve();
	}
	
}
/*
*/
