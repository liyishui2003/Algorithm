#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N = 65;
int half,n,ans=0;
int a[N],sum[N],dp[60*10005];
void solve(int len){
	int mi=a[len];
	len--;
	for(int j=0;j<=sum[n];j++)
		dp[j]=0;
	dp[0]=1;
	for(int i=1;i<=len;i++){
		for(int j=sum[i];j>=0;j--){
			if(j-a[i]>=0){
				dp[j]+=dp[j-a[i]];
			}
		}
	}
	//cout<<"len= "<<len<<'\n';
	for(int i=0;i<=half+mi;i++){
		if(i+mi>half&&i<=half) {
	//		cout<<i<<" "<<half<<" "<<dp[i]<<'\n';
			ans+=dp[i];
		}
	}
	//cout<<ans<<'\n';
}
bool cmp(int a,int b){
	return a>b;
}
signed main(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	half=sum[n]/2;
	for(int i=1;i<=n;i++){
		solve(i);
	}
	cout<<ans;
}
